#include "libtpool.h"

#define LIBTPOOL_INTERNAL
# include "libtpool_internal.h"
#undef LIBTPOOL_INTERNAL

void	tpool_destroy(struct s_tpool *__restrict tpool)
{
	size_t	i;

	i = ~0UL;
	pthread_mutex_lock(&tpool->pool_mutex);
	tpool->stop = true;
	pthread_cond_broadcast(&tpool->work_cond);
	pthread_mutex_unlock(&tpool->pool_mutex);
	tpool_wait(tpool);
	pthread_mutex_destroy(&tpool->pool_mutex);
	pthread_cond_destroy(&tpool->pool_cond);
	pthread_cond_destroy(&tpool->work_cond);
	free(tpool->works);
	free(tpool);
}
