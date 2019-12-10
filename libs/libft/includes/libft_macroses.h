/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_macroses.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:59:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/09 20:41:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MACROSES_H
# define LIBFT_MACROSES_H

# include <stdint.h>
# include <stdbool.h>

/*
**	ft_gnl reading buffer size.
*/
# define BUFF_SIZE 2048
/*
**	Simple macroses for work with bits fields
*/
# include "libft_bits_macroses.h"

/*
**	Most useful macro:
*/
# define MSG(msg) ft_putstr_fd(msg, STDERR_FILENO)
# define MSGN(msg) ft_putendl_fd(msg, STDERR_FILENO)

# define ISARGS(ac, av, usage_msg) {--ac;++av; IFM_F(usage_msg, !ac);}

# define IFR(ex, ret) if ((ex)) {return (ret);}
# define IFMR(msg, ex, ret) if ((ex)) {MSGN(msg); return (ret);}
# define IF_F(ex) if ((ex)) {return (false);}
# define IFDO(ex, do) if ((ex)) {do;}
# define IFDO_F(ex, do) if ((ex)) {do; return (false);}
# define IFDODO_F(ex, do1, do2) if ((ex)) {do1; do2; return (false);}
# define IFDOM(msg, ex, do) if ((ex)) {MSGN(msg); do;}
# define IFDOR(ex, do, ret) {if ((ex)) {do; return(ret);}}
# define IFDOMR(msg, ex, do, ret) if ((ex)) {MSGN(msg); do; return (ret);}
# define IFME(msg, ex, do, ret) if ((ex)) {perror(msg); do; return (ret);}
# define IFM_F(msg, ex) if ((ex)) {MSGN(msg); return (false);}

# define NO(msg, ex, do, ret) if (!(ex)) {MSGN(msg); do; return(ret);}
# define NO_R(ex, ret) if (!(ex)) {return (ret);}
# define NO_F(ex) if (!(ex)) {return (false);}
# define NODO(ex, do) if (!(ex)) {do;}
# define NODO_R(ex, do, ret) if (!(ex)) {do;return(ret);}
# define NODO_F(ex, do) if (!(ex)) {do; return(false);}
# define NODOM_F(msg, ex, do) if (!(ex)) {MSGN(msg); do; return(false);}
# define NOM_F(msg, ex) if (!(ex)) {MSGN(msg); return (false);}
# define NOM_R(msg, ex, ret) if (!(ex)) {MSGN(msg); return (ret);}

# define ARR_SIZE(arr) (sizeof((arr)) / sizeof(*(arr)))
# define SIZEOF(type, x) (sizeof(type) * (x))

# define MALLOC(dest, type, x) (dest) = (type*)ft_memalloc(SIZEOF(type, x))
# define MEM(t, d, x, m) { NOM_F(m, MALLOC(d,t,x)); }

# define FREE(trash, del) if ((trash)) {del((trash));(trash)=NULL;}

# define DEF_STRERR(exe, s) ft_printf(exe ": %s: %s\n", s, strerror(errno))

# define ABS(var) ((var) < 0) ? -(var) : (var)
# define MAX(a, b) (((a) > (b)) ? (a) : (b))

# define TO_STR_LITERAL(str) #str

# ifndef __APPLE__
#  define NON_NULL(p) __nonnull(p)
# else
#  define NON_NULL(p)
# endif

#endif
