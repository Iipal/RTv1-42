#include "tpool.h"

static struct s_tpool_work __attribute__((__nonnull__(1)))
	*in_tpool_work_get(struct s_tpool *restrict tm)
{
	struct s_tpool_work *restrict	work;

	if (!(work = tm->work_first))
		return (NULL);
	if (work->next == NULL)
	{
		tm->work_first = NULL;
		tm->work_last = NULL;
	}
	else
	{
		tm->work_first = work->next;
	}
	return (work);
}

static void __attribute__((,))
	*in_tpool_worker(struct s_tpool *restrict tm)
{
	struct s_tpool_work *restrict	work;

	while (-42)
	{
		pthread_mutex_lock(&(tm->work_mutex));
		if (tm->stop)
			break ;
		if (tm->work_first == NULL)
			pthread_cond_wait(&(tm->work_cond), &(tm->work_mutex));
		work = in_tpool_work_get(tm);
		tm->working_cnt++;
		pthread_mutex_unlock(&(tm->work_mutex));
		if (!!work)
			work->func(work->arg);
		if (!!work)
			free(work);
		pthread_mutex_lock(&(tm->work_mutex));
		if (!(tm->stop) && !(--(tm->working_cnt)) && !(tm->work_first))
			pthread_cond_signal(&(tm->working_cond));
		pthread_mutex_unlock(&(tm->work_mutex));
	}
	tm->thread_cnt--;
	pthread_cond_signal(&(tm->working_cond));
	pthread_mutex_unlock(&(tm->work_mutex));
	return (NULL);
}

struct s_tpool
	*tpool_create(const size_t n_threads)
{
	struct s_tpool	*restrict	tm;
	pthread_t					thread;
	size_t						i;

	assert(!!n_threads);
	assert((tm = (__typeof__(tm))(valloc(sizeof(*tm)))));
	*tm = (struct s_tpool){ .thread_cnt = n_threads };
	pthread_mutex_init(&(tm->work_mutex), NULL);
	pthread_cond_init(&(tm->work_cond), NULL);
	pthread_cond_init(&(tm->working_cond), NULL);
	i = ~0UL;
	while (++i != n_threads)
	{
		pthread_create(&thread, NULL, (void*(*)(void*))in_tpool_worker, tm);
		pthread_detach(thread);
	}
	return (tm);
}
