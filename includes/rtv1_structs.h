/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:09:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/25 19:50:32 by tmaluh           ###   ########.fr       */
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

# define FDOT typedef struct s_fdot fDot

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

struct	s_object
{
	Vec		pos;
	Color	clr;
	int16_t	radius;
	float	spec;
};

struct	s_isrender
{
	bool	is_cam_up;
	bool	is_cam_down;
	bool	is_cam_left;
	bool	is_cam_right;
	bool	is_cam_zinc;
	bool	is_cam_zdec;
	bool	is_render_fps;
	bool	is_cam_speedup;
	bool	is_cam_speeddown;
};

struct	s_time
{
	float	old;
	float	current;
	float	res;
};

# define CAMERA typedef struct s_camera    Camera
# define LIGHT typedef struct s_light      Light
# define OBJECT typedef struct s_object    Object
# define ISRNDR typedef struct s_isrender  Isr
# define TIME typedef struct s_time        Time

CAMERA;
LIGHT;
OBJECT;
ISRNDR;
TIME;

struct	s_scene
{
	Camera	cam;
	Light	l;
	Object	*objs;
	int32_t	ins_objs;
	double	cobj;
};

struct	s_fps
{
	Time	time;
	float	move;
};

# define SCENE typedef struct s_scene   Scene
# define FPS typedef struct s_fps       Fps

SCENE;
FPS;

struct	s_environment
{
	Sdl		*sdl;
	Scene	s;
	Isr		isr;
	Fps		fps;
	double	cam_speed;
};

# define ENV typedef struct s_environment   Environment

ENV;

struct	s_light_help
{
	Vec	cd;
	Vec	p;
	Vec	n;
};

typedef struct s_light_help	t_lhelp;

#endif
