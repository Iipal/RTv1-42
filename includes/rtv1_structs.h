/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:09:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/09 12:28:27 by tmaluh           ###   ########.fr       */
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

typedef double	t_vec __attribute__((vector_size(sizeof(double)*4)));

# define X 0
# define Y 1
# define Z 2
# define T 3

enum	e_type
{
	sphere,
	plain,
	cone,
	cylinder,
	max_objs
};

# define ETYPE typedef enum e_type  Type

ETYPE;

struct	s_camera
{
	t_vec	pos;
	t_vec	dir;
	bool	is;
};

struct	s_light
{
	t_vec	pos;
	float_t	intens;
	bool	is;
};

struct	s_object
{
	t_vec	pos;
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

struct	s_calc_light
{
	t_vec	cd;
	t_vec	p;
	t_vec	n;
	Color	tmp1;
	Color	tmp2;
	t_vec	x;
	float_t	dnl;
	t_vec	h;
	float_t	h_intense;
	float_t	i;
	t_vec	d;
};

typedef struct s_calc_light	t_clhelp;

#endif
