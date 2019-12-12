#include "libtpool.h"

#define LIBTPOOL_INTERNAL
# include "libtpool_internal.h"
#undef LIBTPOOL_INTERNAL

bool	tpool_add_work(struct s_tpool *restrict tpool,
			void (*work_routine)(void *restrict),
			void *arg)
{
	size_t	i;

	i = ~0UL;
	pthread_mutex_lock(&tpool->pool_mutex);
	while (tpool->pool_size > ++i)
		if (!tpool->works[i].routine)
			break ;
	if (tpool->pool_size > i) {
		tpool->works[i] = (struct s_worker) {
			.routine = work_routine,
			.arg = arg
		};
		pthread_cond_broadcast(&tpool->work_cond);
		pthread_mutex_unlock(&tpool->pool_mutex);
		return (true);
	}
	pthread_mutex_unlock(&tpool->pool_mutex);
	return (false);
}
