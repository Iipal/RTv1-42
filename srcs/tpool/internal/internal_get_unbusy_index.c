#include "libtpool.h"

#define LIBTPOOL_INTERNAL
# include "libtpool_internal.h"
#undef LIBTPOOL_INTERNAL

ptrdiff_t __attribute__((__const__))
	internal_get_unbusy_index(const ptrdiff_t busy_works_mask)
{
	ptrdiff_t	i = -1L;

	while (64L > ++i)
		if (!(busy_works_mask & (1 << i)))
			return (i);
	return (0L);
}
