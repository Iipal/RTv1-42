/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:09:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/09 00:39:57 by tmaluh           ###   ########.fr       */
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

struct	s_vec
{
	double_t	x;
	double_t	y;
	double_t	z;
};

struct	s_fdot
{
	float_t	x;
	float_t	y;
};

enum	e_type
{
	sphere,
	plain,
	cone,
	cylinder,
	max_objs
};

# define FDOT typedef struct s_fdot fDot
# define VEC typedef struct s_vec   Vec
# define ETYPE typedef enum e_type  Type

FDOT;
VEC;
ETYPE;

struct	s_camera
{
	Vec		pos;
	Vec		dir;
	bool	is;
};

struct	s_light
{
	Vec		pos;
	float_t	intensity;
	bool	is;
};

struct	s_object
{
	Vec		pos;
	Color	clr;
	int16_t	radius;
	float_t	spec;
	Type	type;
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
	bool	is_debug;
};

struct	s_time
{
	float_t	old;
	float_t	current;
	float_t	res;
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
	Camera		cam;
	Light		l;
	Object		*objs;
	int32_t		ins_objs;
	double_t	cobj;
};

struct	s_fps
{
	Time	time;
	float_t	move;
};

# define SCENE typedef struct s_scene   Scene
# define FPS typedef struct s_fps       Fps

SCENE;
FPS;

struct	s_environment
{
	Sdl			*sdl;
	Scene		s;
	Isr			isr;
	Fps			fps;
	double_t	cam_speed;
	double_t	t_max;
	double_t	t_min;
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

struct	s_calc_light
{
	Object	obj;
	Vec		p;
	Vec		n;
	Light	l;
	float_t	s;
	Vec		v;
};

typedef struct s_calc_light	t_clhelp;

#endif
