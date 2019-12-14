#include "libtpool.h"

#define LIBTPOOL_INTERNAL
# include "libtpool_internal.h"
#undef LIBTPOOL_INTERNAL

#include <stdio.h>

static inline struct s_current_work
	s_get_work(const struct s_tpool *restrict tpool)
{
	size_t	i;

	i = ~0UL;
	while (tpool->pool_size > ++i)
		if (!!tpool->works[i].routine && !(tpool->done_works_mask & (1L << (ptrdiff_t)i)))
			return ((struct s_current_work) { tpool->works[i], 1L << (ptrdiff_t)i });
	return ((struct s_current_work) { { NULL, NULL }, 0L });
}

void
	*internal_thread_worker(void *restrict arg)
{
	struct s_tpool *restrict		tpool = (struct s_tpool *restrict)arg;
	struct s_current_work			*c_work = valloc(sizeof(*c_work));

	assert(arg);
	assert(c_work);
	while (1) {
		pthread_mutex_lock(&tpool->pool_mutex);
		if (tpool->stop)
		 	break ;
		if (!tpool->works_count)
			pthread_cond_wait(&tpool->work_cond, &tpool->pool_mutex);
		*c_work = s_get_work(tpool);
		tpool->done_works_mask |= c_work->work_mask_index;
		++tpool->works_count;
		pthread_mutex_unlock(&tpool->pool_mutex);
		if (c_work->work.routine && c_work->work.arg)
			c_work->work.routine(c_work->work.arg);
		pthread_mutex_lock(&tpool->pool_mutex);
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
