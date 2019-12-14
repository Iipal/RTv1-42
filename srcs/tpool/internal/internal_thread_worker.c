#include "libtpool.h"

#define LIBTPOOL_INTERNAL
# include "libtpool_internal.h"
#undef LIBTPOOL_INTERNAL

#include <stdio.h>

static struct s_work	s_get_work(struct s_tpool *__restrict tpool)
{
	struct s_work	out;
	size_t			i;

	i = ~0UL;
	out = (struct s_work) { NULL, NULL };
	while (tpool->pool_size > ++i)
		if (!!tpool->works[i].routine) {
			out = tpool->works[i];
			tpool->works[i] = (struct s_work) { NULL, NULL };
			break ;
		}
	return (out);
}

void *__nullable	internal_thread_worker(void *__restrict __nonnull arg)
{
	struct s_tpool *__restrict	tpool = (struct s_tpool *__restrict)arg;
	struct s_work				work;

	while (1) {
		pthread_mutex_lock(&tpool->pool_mutex);
		if (tpool->stop)
		 	break ;
		if (!tpool->works_count)
			pthread_cond_wait(&tpool->work_cond, &tpool->pool_mutex);
		work = s_get_work(tpool);
		++tpool->works_count;
		pthread_mutex_unlock(&tpool->pool_mutex);
		if (work.routine && work.arg)
			work.routine(work.arg);
		pthread_mutex_lock(&tpool->pool_mutex);
		--tpool->works_count;
		work = (struct s_work) { NULL, NULL };
		if (!tpool->stop && !tpool->works_count)
			pthread_cond_signal(&tpool->pool_cond);
		pthread_mutex_unlock(&tpool->pool_mutex);
	}
	tpool->threads_count--;
	pthread_cond_signal(&tpool->pool_cond);
	pthread_mutex_unlock(&tpool->pool_mutex);
	return (NULL);
}
