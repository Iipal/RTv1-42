#include "libtpool.h"

#define LIBTPOOL_INTERNAL
# include "libtpool_internal.h"
#undef LIBTPOOL_INTERNAL

void	tpool_wait(struct s_tpool *__restrict tpool)
{
	pthread_mutex_lock(&tpool->pool_mutex);
	while (1) {
		if ((!tpool->stop && tpool->works_count)
		|| (tpool->stop && tpool->threads_count))
			pthread_cond_wait(&tpool->pool_cond, &tpool->pool_mutex);
		else
			break ;
	}
	pthread_mutex_unlock(&tpool->pool_mutex);
}
