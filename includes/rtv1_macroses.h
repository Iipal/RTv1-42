/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_macroses.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:12:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/11 15:30:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_MACROSES_H
# define RTV1_MACROSES_H

# define RTV1_TITLE     "Ray Tracing v1"
# define RTV1_EXE_PATH  "./RTv1"
# define RTV1_FILEXT    ".rtv1"

# define WIN_MIN_X	400
# define WIN_MIN_Y	400

# ifdef __APPLE__
#  define WIN_MAX_X 2000
#  define WIN_MAX_Y 1000
# endif

# ifdef __linux__
#  define WIN_MAX_X 1000
#  define WIN_MAX_Y 500
# endif

# define IFDO(ex, do) if ((ex)) {do;}
# define IFDOR(ex, do, ret) if ((ex)) {do; return(ret);}

# define MSG(msg) ft_putstr(msg)
# define MSGN(msg) ft_putendl(msg)
# define NOTIS(msg, ex, do, ret) if (!(ex)) {MSGN(msg); do; return(ret);}
# define NOTIS_F(ex) if (!(ex)) return (false)
# define ISARGS(ac, av) {--ac;++av; NOTIS(E_USAGE, !(ac != 1), exit(1), 0);}
# define ISM(msg, ex, do, ret) if ((ex)) {MSGN(msg); do; return (ret);}

# define Z(type, dest, x) ft_bzero(dest, sizeof(type) * (x))
# define MEM(t, d, x, m) NOTIS(m,d=(t*)malloc(sizeof(t)*(x)),exit(1),0);Z(t,d,x)

# define FREE(trash, del) if ((trash)) {del((trash)); (trash) = NULL;}

# define ABS(var) ((var) < 0) ? -(var) : (var)

# define RGB_BLACK	0x00

#endif
