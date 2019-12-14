#include "libtpool.h"

#define LIBTPOOL_INTERNAL
# include "libtpool_internal.h"
#undef LIBTPOOL_INTERNAL

bool	tpool_add_work(struct s_tpool *restrict tpool,
			void (*work_routine)(void *restrict),
			void *arg)
{
	size_t	i;

	pthread_mutex_lock(&tpool->pool_mutex);
	i = ~0UL;
	while (tpool->pool_size > ++i)
		if (!tpool->works[i].routine) {
			tpool->works[i] = (struct s_work) { work_routine, arg };
			break ;
		}
	pthread_cond_broadcast(&tpool->work_cond);
	pthread_mutex_unlock(&tpool->pool_mutex);
	return (true);
}
