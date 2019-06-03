/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_macroses.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:12:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/03 09:49:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_MACROSES_H
# define RTV1_MACROSES_H

# ifdef __APPLE__
#  define WIN_X 2000
#  define WIN_Y 1000

#  define RT_CANVAS_STARTX   -1000
#  define RT_CANVAS_STARTY   -500
#  define RT_CANVAS_ENDX     1000
#  define RT_CANVAS_ENDY     500
# endif

/*
** RT_CANVAS_STARTX equals to: -(WIN_X / 2)
** RT_CANVAS_STARTY equals to: -(WIN_Y / 2)
** RT_CANVAS_ENDX   equals to: WIN_X / 2
** RT_CANVAS_ENDY   equals to: WIN_Y / 2
*/

# ifdef __linux__
#  define WIN_X 800
#  define WIN_Y 400

#  define RT_CANVAS_STARTX   -450
#  define RT_CANVAS_STARTY   -225
#  define RT_CANVAS_ENDX     450
#  define RT_CANVAS_ENDY     225
# endif

# define MAX(a, b) (((a) > (b)) ? (a) : (b))

# define TMAX           100000.0
# define TMIN           0.000001

# define TO_RAD(deg) (((deg) * M_PI) / 180.0)
# define COS_RAD(angle) cos(TO_RAD(angle))
# define SIN_RAD(angle) sin(TO_RAD(angle))

# define MOVE_INC 5
# define MOVE_SPEED_PERCENT_DEFAULT 1.0f
# define MOVE_SPEED_PERCENT_SUP     3.5f
# define MOVE_SPEED_PERCENT_SDOWN   .15f
# define MOVE_SPEED_PERCENT_STEP    .05f

# define RTV1_TITLE         "Ray Tracing v1"

# define RTV1_EXE_PATH      "./RTv1"
# define RTV1_FILEXT        ".rtv1"

# define RTV1_MAIN_USAGE    "Usage: ./RTv1 [flags-params] <scene_name>.rtv1"
# define RTV1_USAGE         "text/usage.txt"
# define RTV1_FHELP         "text/flags_usage.txt"

#endif
