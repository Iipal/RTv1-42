#ifndef LIBTPOOL_INTERNAL_H
# define LIBTPOOL_INTERNAL_H

# ifndef LIBTPOOL_INTERNAL
#  error "include libtpool.h only"
# endif

# include <stdlib.h>
# include <stddef.h>
# include <pthread.h>
# include <assert.h>

# ifndef S_WORKER
#  define S_WORKER

struct	s_worker
{
	void	(*routine)(void *restrict);
	void	*arg;
};

# endif

# ifndef S_TPOOL
#  define S_TPOOL

struct	s_tpool
{
	struct s_worker	*works;
	size_t			works_count;
	size_t			threads_count;
	size_t			pool_size;
	pthread_mutex_t	pool_mutex;
	pthread_cond_t	pool_cond;
	pthread_cond_t	work_cond;
	int				stop;
};

# endif

#endif /* LIBTPOOL_INTERNAL_H */
