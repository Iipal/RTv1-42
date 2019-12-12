#include "libtpool.h"

#define LIBTPOOL_INTERNAL
# include "libtpool_internal.h"
#undef LIBTPOOL_INTERNAL

static struct s_worker
	*s_get_work(const struct s_tpool *restrict tpool)
{
	size_t	i;

	i = ~0UL;
	while (tpool->pool_size > ++i)
		if (tpool->works && tpool->works[i].routine && !tpool->works[i].busy)
			break ;
	if (tpool->pool_size > i)
		return (&tpool->works[i]);
	return (NULL);
}

#include <stdio.h>
static void
	*s_thread_work(void *restrict arg)
{
	struct s_tpool *restrict	tpool = (struct s_tpool *restrict)arg;
	struct s_worker *restrict	work;

	work = NULL;
	while (1) {
		pthread_mutex_lock(&tpool->pool_mutex);
		if (tpool->stop)
		 	break ;
		if (!tpool->works_count)
			pthread_cond_wait(&tpool->work_cond, &tpool->pool_mutex);
		work = s_get_work(tpool);
		work->busy = 1;
		pthread_mutex_unlock(&tpool->pool_mutex);
		if (work && work->routine)
			work->routine(work->arg);
		pthread_mutex_lock(&tpool->pool_mutex);
		work->busy = 0;
		--tpool->works_count;
		if (!tpool->stop && !tpool->works_count)
			pthread_cond_signal(&tpool->pool_cond);
		pthread_mutex_unlock(&tpool->pool_mutex);
	}
	tpool->threads_count--;
	pthread_cond_signal(&tpool->pool_cond);
	pthread_mutex_unlock(&tpool->pool_mutex);
	return (NULL);
}

struct s_tpool
	*tpool_create(const size_t threads_count)
{
	struct s_tpool	*tpool;
	pthread_t		thread;
	size_t			i;

	assert(threads_count);
	assert((tpool = calloc(1UL, sizeof(*tpool))));
	*tpool = (struct s_tpool) { .pool_size = threads_count,
								.threads_count = threads_count };
	assert((tpool->works = calloc(threads_count, sizeof(*tpool->works))));
	const ptrdiff_t	diff = (void*)tpool->works - (void*)tpool;
	(void)diff;
	pthread_mutex_init(&tpool->pool_mutex, NULL);
	pthread_cond_init(&tpool->work_cond, NULL);
	pthread_cond_init(&tpool->pool_cond, NULL);
	i = ~0UL;
	while (threads_count > ++i) {
		pthread_create(&thread, NULL, s_thread_work, tpool);
		pthread_detach(thread);
	}
	return (tpool);
}
