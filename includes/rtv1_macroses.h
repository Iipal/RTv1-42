/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_macroses.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:12:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/13 21:15:34 by tmaluh           ###   ########.fr       */
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

# define RT_CANVAS_STARTX   -(WIN_X / 2)
# define RT_CANVAS_STARTY   -(WIN_Y / 2)
# define RT_CANVAS_ENDX     WIN_X / 2
# define RT_CANVAS_ENDY     WIN_Y / 2

# define TMIN   0.001f
# define TMAX   10000.0f

# define MAX_LIGHTS 5

# define MOVE_INC 5
# define MOVE_SPEED_PERCENT_DEFAULT 1.0f
# define MOVE_SPEED_PERCENT_SUP 3.5f
# define MOVE_SPEED_PERCENT_SDOWN .15f
# define MOVE_SPEED_PERCENT_STEP .05f

# define RTV1_TITLE     "Ray Tracing v1"
# define RTV1_EXE_PATH  "./RTv1"
# define RTV1_FILEXT    ".rtv1"
# define RTV1_USAGE     "text/usage.txt"
# define RTV1_FHELP     "text/flags_help.txt"

# define FP_CAM         "Camera:"
# define FP_LIGHT       "Light:"
# define FP_SPHERE      "Sphere:"
# define FP_CONE        "Cone:"
# define FP_PLANE       "Plane:"
# define FP_CYLINDER    "Cylinder:"
# define FP_MAX_OBJS    4

# define F_HELP     "--help"
# define F_VPS      "--viewport-scale"
# define F_SB       "--shadow-bright"

# define SF_HELP    "-h"
# define SF_VPS     "-vps"
# define SF_SB      "-sb"

# define MAX_FLAGS  3

# define REFRESH_FPS_COUNTER .1f

# define VLEN(v) sqrt(X(v) * X(v) + Y(v) * Y(v) + Z(v) * Z(v))
# define VDOT(v1, v2) (X(v1) * X(v2) + Y(v1) * Y(v2) + Z(v1) * Z(v2))

# define OBJ(i) sc->objs[i]
# define SEKEY env->sdl->e.key.keysym.sym

typedef bool (*t_fn_fparse)(Flags*, char**, const size_t, size_t*);
# define FNSCP typedef bool (*fns_parse)(Scene*, char*, size_t*);

FNSCP;

#endif
