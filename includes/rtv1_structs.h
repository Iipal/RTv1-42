/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:09:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/16 17:05:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTS_H
# define RTV1_STRUCTS_H

# include "libft.h"

# ifdef __APPLE__
#  include "../frameworks/SDL2.framework/Headers/SDL.h"
# endif

# ifdef __linux__
#  include <SDL2/SDL.h>
# endif

# define IARR   typedef int32_t*    iarr
# define ITAB   typedef int32_t**   itab
# define UIARR  typedef uint32_t*   uiarr
# define UINT   typedef uint32_t    uint

IARR;
ITAB;
UIARR;
UINT;

struct s_vec
{
	double	x;
	double	y;
	double	z;
};

# define VEC typedef struct s_vec   Vec

VEC;

struct s_ray
{
	Vec	o;
	Vec	dir;
};

struct	s_fdot
{
	float	x;
	float	y;
};

struct	s_dot
{
	int32_t	x;
	int32_t	y;
};

# define RAY typedef struct s_ray   Ray
# define DOT typedef struct s_dot   Dot
# define FDOT typedef struct s_fdot fDot

RAY;
DOT;
FDOT;

struct	s_camera
{
	Vec	pos;
	Vec	dir;
};

# define CAMERA typedef struct s_camera    Camera

CAMERA;

struct	s_enviroment
{
	Sdl		*sdl;
	Camera	cam;
	Color	color;
};

# define ENV typedef struct s_enviroment    Environment

ENV;

#endif
