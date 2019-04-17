/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:09:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/17 18:49:57 by tmaluh           ###   ########.fr       */
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
	float	intensity;
	bool	is;
};

struct	s_sphere
{
	Vec		pos;
	Uint32	clr;
	int16_t	radius;
	float	spec;
	bool	is;
};

struct	s_object
{
	Vec		pos;
	Uint32	clr;
	int16_t	radius;
	float	spec;
};

# define CAMERA typedef struct s_camera    Camera
# define LIGHT typedef struct s_light      Light
# define SPHERE typedef struct s_sphere    Sphere
# define OBJ typedef struct s_object       Object

CAMERA;
LIGHT;
SPHERE;
OBJ;

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
	Object	*obj;
	uint8_t	max_objs;
};

# define ENV typedef struct s_environment   Environment

ENV;

#endif
