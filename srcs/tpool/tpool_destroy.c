#include "tpool.h"

void __attribute__((__nonnull__(1)))
	tpool_destroy(struct s_tpool *restrict tm)
{
	struct s_tpool_work *restrict	work;
	struct s_tpool_work *restrict	work2;

	pthread_mutex_lock(&(tm->work_mutex));
	work = tm->work_first;
	while (!!work)
	{
		work2 = work->next;
		free(work);
		work = work2;
	}
	tm->stop = true;
	pthread_cond_broadcast(&(tm->work_cond));
	pthread_mutex_unlock(&(tm->work_mutex));
	tpool_wait(tm);
	pthread_mutex_destroy(&(tm->work_mutex));
	pthread_cond_destroy(&(tm->work_cond));
	pthread_cond_destroy(&(tm->working_cond));
	free((void*)tm);
}
