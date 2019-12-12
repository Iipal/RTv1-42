#include "libtpool.h"

#define LIBTPOOL_INTERNAL
# include "libtpool_internal.h"
#undef LIBTPOOL_INTERNAL

bool	tpool_add_work(struct s_tpool *restrict tpool,
			void (*work_routine)(void *restrict),
			void *arg)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(&tpool->pool_mutex);
	if (tpool->works_count < tpool->pool_size) {
		tpool->works[tpool->works_count++] = (struct s_worker) {
			.routine = work_routine,
			.arg = arg,
			.busy = 0
		};
		pthread_cond_broadcast(&tpool->work_cond);
		ret = true;
	}
	pthread_mutex_unlock(&tpool->pool_mutex);
	return (ret);
}
