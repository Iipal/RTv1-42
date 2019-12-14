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
*__nonnull tpool_create(const size_t threads_count);

bool
tpool_add_work(struct s_tpool *__restrict __nonnull tpool,
	void (*__nonnull work_routine)(void *__nonnull),
	void *__restrict __nonnull arg);

void
tpool_wait(struct s_tpool *__restrict __nonnull tpool);

void
tpool_destroy(struct s_tpool *__restrict __nonnull tpool);

# ifdef ONLY_LOCAL_GNU_SOURCE_DEFINE
#  undef ONLY_LOCAL_GNU_SOURCE_DEFINE
#  undef _GNU_SOURCE
# endif

#endif /* LIBTPOOL_H */
