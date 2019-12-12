#ifndef LIBTPOOL_H
# define LIBTPOOL_H

# ifndef _GNU_SOURCE
#  define ONLY_LOCAL_GNU_SOURCE_DEFINE
#  define _GNU_SOURCE
# endif

# include <sys/types.h>
# include <stdbool.h>

struct s_tpool;

struct s_tpool
*tpool_create(const size_t threads_count);

bool
tpool_add_work(struct s_tpool *restrict tpool,
	void (*work_routine)(void *restrict),
	void *restrict arg);

void
tpool_wait(struct s_tpool *restrict tpool);

void __attribute__((__nonnull__(1)))
tpool_destroy(struct s_tpool *restrict tpool);

size_t __attribute__((__nonnull__(1)))
tpool_size(const struct s_tpool *restrict tpool);

size_t __attribute__((__nonnull__(1)))
tpool_alive(const struct s_tpool *restrict tpool);

# ifdef ONLY_LOCAL_GNU_SOURCE_DEFINE
#  undef ONLY_LOCAL_GNU_SOURCE_DEFINE
#  undef _GNU_SOURCE
# endif

#endif /* LIBTPOOL_H */
