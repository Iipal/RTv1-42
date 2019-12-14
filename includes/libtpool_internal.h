#ifndef LIBTPOOL_INTERNAL_H
# define LIBTPOOL_INTERNAL_H

# ifndef LIBTPOOL_INTERNAL
#  error "include libtpool.h only"
# endif

# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <pthread.h>
# include <assert.h>

# ifndef S_WORK
#  define S_WORK

struct	s_work
{
	void	(*routine)(void *restrict);
	void	*arg;
};

# endif

# ifndef S_CURRENT_WORK
#  define S_CURRENT_WORK

struct	s_current_work
{
	struct s_work	work;
	ptrdiff_t		work_mask_index;
};

# endif


# ifndef S_TPOOL
#  define S_TPOOL

struct	s_tpool
{
	struct s_work	*works;
	ptrdiff_t		done_works_mask;
	size_t			works_count;
	size_t			threads_count;
	size_t			pool_size;
	pthread_mutex_t	pool_mutex;
	pthread_cond_t	pool_cond;
	pthread_cond_t	work_cond;
	int				stop;
};

# endif

ptrdiff_t __attribute__((__const__))
internal_get_unbusy_index(const ptrdiff_t busy_works_mask);
void
*internal_thread_worker(void *restrict arg);

#endif /* LIBTPOOL_INTERNAL_H */
