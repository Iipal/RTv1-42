/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:09:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/17 12:36:24 by tmaluh           ###   ########.fr       */
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

struct	s_vec
{
	double	x;
	double	y;
	double	z;
};

# define VEC typedef struct s_vec   Vec

VEC;

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

# define DOT typedef struct s_dot   Dot
# define FDOT typedef struct s_fdot fDot

DOT;
FDOT;

struct	s_camera
{
	Vec		pos;
	Vec		dir;
	bool	is;
};

struct	s_light
{
	Vec		pos;
	float	intense;
	bool	is;
};

struct	s_sphere
{
	Vec		pos;
	Uint32	clr;
	int16_t	radius;
	int16_t	spec;
	bool	is;
};

# define CAMERA typedef struct s_camera    Camera
# define LIGHT typedef struct s_light      Light
# define SPHERE typedef struct s_sphere    Sphere

CAMERA;
LIGHT;
SPHERE;

struct	s_scene
{
	Camera	cam;
	Light	l;
	Sphere	sp;
};

# define SCENE typedef struct s_scene        Scene

SCENE;

struct	s_environment
{
	Sdl		*sdl;
	Color	color;
	Scene	s;
};

# define ENV typedef struct s_environment   Environment

ENV;

#endif
