/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_macroses.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:12:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/20 16:22:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_MACROSES_H
# define RTV1_MACROSES_H

# ifdef __APPLE__
#  define WIN_X 2000
#  define WIN_Y 1000
# endif

# ifdef __linux__
#  define WIN_X 1300
#  define WIN_Y 650
# endif

# define MAX_X  1500
# define MAX_Z  1500
# define MAX_Y  1500

# define MIN_X  -MAX_X
# define MIN_Z  -MAX_Z
# define MIN_Y  -MAX_Y

# define TMAX           10000.0f
# define TMIN           0.001f

# define MAX_RADIUS     500
# define MIN_RADIUS     0

# define MAX_SPEC       10000
# define MIN_SPEC       0

# define MAX_ROT_ANGLE  360.0f
# define MIN_ROT_ANGLE  -MAX_ROT_ANGLE

# define MAX_LIGHTS     5
# define MAX_L_INTENS   1.0f
# define MIN_L_INTENS   .0f

# define RT_CANVAS_STARTX   -(WIN_X / 2)
# define RT_CANVAS_STARTY   -(WIN_Y / 2)
# define RT_CANVAS_ENDX     WIN_X / 2
# define RT_CANVAS_ENDY     WIN_Y / 2

# define MOVE_INC 5
# define MOVE_SPEED_PERCENT_DEFAULT 1.0f
# define MOVE_SPEED_PERCENT_SUP 3.5f
# define MOVE_SPEED_PERCENT_SDOWN .15f
# define MOVE_SPEED_PERCENT_STEP .05f

# define RTV1_TITLE     "Ray Tracing v1"

# define RTV1_EXE_PATH  "./RTv1"
# define RTV1_FILEXT    ".rtv1"

# define RTV1_USAGE     "text/usage.txt"
# define RTV1_FHELP     "text/flags_usage.txt"

# define FP_CAM         "Camera:"
# define FP_LIGHT       "Light:"

# define FP_MAX_OBJS    4
# define FP_SPHERE      "Sphere:"
# define FP_CONE        "Cone:"
# define FP_PLANE       "Plane:"
# define FP_CYLINDER    "Cylinder:"

# define MAX_FLAGS  5
# define F_HELP     "--help"
# define F_VPS      "--viewport-scale"
# define F_SB       "--shadow-bright"
# define F_FTC      "--fps-text-color"
# define F_DBG      "--debug"

# define SF_HELP    "-h"
# define SF_VPS     "-vps"
# define SF_SB      "-sb"
# define SF_FTC     "-ftc"
# define SF_DBG     "-dbg"

# define DEF_VIEWPORT_SCALE 1.0f
# define DEF_SHADOW_BRIGHT  100.0f
# define DEF_FPS_TEXT_COLOR 0x7FFF00
# define DEF_DEBUG_MODE     false

# define REFRESH_FPS_COUNTER .25f

#endif
