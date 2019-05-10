/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_macroses.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:12:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/10 16:02:34 by tmaluh           ###   ########.fr       */
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

# define MAX_X  1500
# define MAX_Z  1500
# define MAX_Y  1500

# define MIN_X  -MAX_X
# define MIN_Z  -MAX_Z
# define MIN_Y  -MAX_Y

# define MAX_SPR    500
# define MIN_SPR    0

# define MAX_SPSP   5000
# define MIN_SPSP   0

# define RT_SX  -(WIN_X / 2)
# define RT_SY  -(WIN_Y / 2)
# define RT_EX  WIN_X / 2
# define RT_EY  WIN_Y / 2

# define TMIN   0.001f
# define TMAX   10000.0f

# define MOVE_INC 5
# define MOVE_SPEED_PERCENT_DEFAULT 1.0f
# define MOVE_SPEED_PERCENT_SUP 2.5f
# define MOVE_SPEED_PERCENT_SDOWN .25f
# define MOVE_SPEED_PERCENT_STEP .05f

# define RTV1_TITLE     "Ray Tracing v1"
# define RTV1_EXE_PATH  "./RTv1"
# define RTV1_FILEXT    ".rtv1"
# define RTV1_USAGE     "text/usage.txt"

# define FP_CAM     "Camera:"
# define FP_LIGHT   "Light:"
# define FP_SPHERE  "Sphere:"

# define REFRESH_FPS_COUNTER .1f

# define VLEN(v) sqrt(v[X] * v[X] + v[Y] * v[Y] + v[Z] * v[Z])
# define VDOT(v1, v2) (v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z])
# define VMULT(v1, m) { v1[X] * m; v1[Y] * m; v1[Z] * m; }

# define OBJ(i) sc->objs[i]
# define SEKEY env->sdl->e.key.keysym.sym

# define RGB_BLACK 0x00

# define FNSCP typedef bool (*fns_parse)(Scene*, string, int32_t*);

FNSCP;

#endif
