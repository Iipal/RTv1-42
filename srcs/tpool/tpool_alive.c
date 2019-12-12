#include "libtpool.h"

#define LIBTPOOL_INTERNAL
# include "libtpool_internal.h"
#undef LIBTPOOL_INTERNAL

size_t	tpool_alive(const struct s_tpool *restrict tpool)
{
	return (tpool->threads_count);
}
