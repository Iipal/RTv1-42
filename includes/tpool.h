#ifndef TPOOL_H
# define TPOOL_H

# pragma GCC diagnostic ignored "-Wlong-long"
# pragma GCC diagnostic ignored "-Wpadded"
# pragma GCC diagnostic ignored "-Wredundant-decls"
# include <stddef.h>
# include <pthread.h>
# include <assert.h>

# if defined(__APPLE__)
#  include <stdlib.h>
# else
#  include <malloc.h>
# endif

# include <stdbool.h>
# pragma GCC diagnostic warning "-Wredundant-decls"
# pragma GCC diagnostic ignored "-Wpadded"
# pragma GCC diagnostic warning "-Wlong-long"

# ifndef S_TPOOL_WORK
#  define S_TPOOL_WORK
struct					s_tpool_work
{
	void							(*func)(void*);
	void				*restrict	arg;
	struct s_tpool_work	*restrict	next;
};
# endif

# ifndef S_TPOOL
#  define S_TPOOL
struct					s_tpool
{
	struct s_tpool_work *restrict	work_first;
	struct s_tpool_work *restrict	work_last;
	pthread_mutex_t					work_mutex;
	pthread_cond_t					work_cond;
	pthread_cond_t					working_cond;
	size_t							working_cnt;
	size_t							thread_cnt;
	_Bool							stop;
	char							stub[7];
};
# endif

extern struct s_tpool	*tpool_create(const size_t n_threads);
extern void				tpool_destroy(struct s_tpool *restrict tm);
extern _Bool			tpool_add_work(struct s_tpool *restrict tm,
							void (*routine)(void*),
							void *arg);
extern void				tpool_wait(struct s_tpool *restrict tm);

#endif
