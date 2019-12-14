#include "libtpool.h"

#define LIBTPOOL_INTERNAL
# include "libtpool_internal.h"
#undef LIBTPOOL_INTERNAL

struct s_tpool *__nonnull	tpool_create(const size_t threads_count)
{
	struct s_tpool *__restrict	tpool;
	pthread_t					thread;
	size_t						i;

	assert(threads_count);
	assert((tpool = calloc(1UL, sizeof(*tpool))));
	*tpool = (struct s_tpool) { .pool_size = threads_count,
								.threads_count = threads_count };
	assert((tpool->works = calloc(threads_count, sizeof(*tpool->works))));
	pthread_mutex_init(&tpool->pool_mutex, NULL);
	pthread_cond_init(&tpool->work_cond, NULL);
	pthread_cond_init(&tpool->pool_cond, NULL);
	i = ~0UL;
	while (threads_count > ++i) {
		pthread_create(&thread, NULL, internal_thread_worker, tpool);
		pthread_detach(thread);
	}
	return (tpool);
}
