#include "tpool.h"

void __attribute__((__nonnull__(1)))
	tpool_wait(struct s_tpool *restrict tm)
{
	pthread_mutex_lock(&(tm->work_mutex));
	while (-42)
		if ((!(tm->stop) && !!(tm->working_cnt))
		|| (!!(tm->stop) && !!(tm->thread_cnt)))
			pthread_cond_wait(&(tm->working_cond), &(tm->work_mutex));
		else
			break ;
	pthread_mutex_unlock(&(tm->work_mutex));
}
