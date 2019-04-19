/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_macroses.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:12:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/19 12:29:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_MACROSES_H
# define RTV1_MACROSES_H

# ifdef __APPLE__
#  define WIN_X 2000
#  define WIN_Y 1000
# endif

# ifdef __linux__
#  define WIN_X 1000
#  define WIN_Y 500
# endif

# define MIN_X  -250
# define MIN_Z  -250
# define MIN_Y  -250

# define MAX_X  250
# define MAX_Z  250
# define MAX_Y  250

# define RT_SX  -(WIN_X / 2)
# define RT_SY  -(WIN_Y / 2)
# define RT_EX  WIN_X / 2
# define RT_EY  WIN_Y / 2

# define TMIN   0.1
# define TMAX   10000

# define RTV1_TITLE     "Ray Tracing v1"
# define RTV1_EXE_PATH  "./RTv1"
# define RTV1_FILEXT    ".rtv1"
# define RTV1_USAGE     "text/usage.txt"

# define FP_CAM     "Camera:"
# define FP_LIGHT   "Light:"
# define FP_SPHERE  "Sphere:"

# define MAX_CAM_PARAMS 6

# define VMUL(a, b) u_mul_vec((a), (b))

# define RGB_BLACK  0x00

#endif
