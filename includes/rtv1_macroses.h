/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_macroses.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:12:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/11 01:43:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_MACROSES_H
# define RTV1_MACROSES_H

# define RTV1_TITLE "Ray Tracing v1"

# ifdef __APPLE__
#  define WIN_X 2000
#  define WIN_Y 1000
# endif

# ifdef __linux__
#  define WIN_X 800
#  define WIN_Y 400
# endif

# define RTV1_EXE_PATH "./RTv1"
# define RTV1_FILEXT   ".json"

# define RTV1_USAGE    "text/usage.txt"
# define RTV1_FUSAGE   "text/flags_usage.txt"

# define RT_CANVAS_STARTX -(WIN_X / 2)
# define RT_CANVAS_STARTY -(WIN_Y / 2)
# define RT_CANVAS_ENDX   WIN_X / 2
# define RT_CANVAS_ENDY   WIN_Y / 2

# define TMAX 100000.0
# define TMIN 0.000001

# ifdef M_PI
#  undef M_PI
# endif
# define M_PI 3.14159265358979323846

# define TO_RAD(deg) (((deg) * M_PI) / 180.0)
# define COS_RAD(angle) cos(TO_RAD(angle))
# define SIN_RAD(angle) sin(TO_RAD(angle))

# define MOVE_INC                   5
# define MOVE_SPEED_PERCENT_DEFAULT 1.0f
# define MOVE_SPEED_PERCENT_SUP     3.5f
# define MOVE_SPEED_PERCENT_SDOWN   .15f
# define MOVE_SPEED_PERCENT_STEP    .05f

# define FPS_MAX_BUFF_SIZE 16

#endif
