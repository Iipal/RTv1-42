/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:09:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/18 23:50:53 by tmaluh           ###   ########.fr       */
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

enum	e_type
{
	sphere,
	plane,
	cone,
	cylinder,
	max_objs
};

# define ETYPE typedef enum e_type  Type

ETYPE;

struct	s_camera
{
	Vector	pos;
	Vector	dir;
	bool	is;
};

struct	s_light
{
	Vector		pos;
	double_t	intens;
};

typedef Vector	(*t_fn_inter)(const Vector,
							const Vector,
							void const *restrict const);
typedef Vector	(*t_fn_normal)(const Vector,
							const Vector,
							struct s_camera const *restrict const,
							void const *restrict const);

struct	s_object
{
	Vector		pos;
	Vector		dir;
	Color		clr;
	double_t	radius;
	double_t	spec;
	Type		type;
	t_fn_inter	fn_inter_calc;
	t_fn_normal	fn_normal_calc;
};

struct	s_isrender
{
	bool	is_up;
	bool	is_down;
	bool	is_left;
	bool	is_right;
	bool	is_zinc;
	bool	is_zdec;
	bool	is_render_fps;
	bool	is_speedup;
	bool	is_speeddown;
	bool	is_light_debug;
	bool	is_objs_debug;
	bool	is_debug_zorintens;
};

struct	s_time
{
	float_t	old;
	float_t	current;
	float_t	res;
	float_t	ms;
	float_t	fps;
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
	Light		*l;
	Object		*objs;
	size_t		ins_l;
	size_t		ins_objs;
	double_t	cobj;
};

struct	s_fps
{
	Time		time;
	double_t	move;
	double_t	l_move;
	double_t	l_intens;
	double_t	o_spec_intens;
};

struct	s_flags
{
	float_t	viewport_scale;
	float_t	shadows_bright;
	Uint32	fps_text_color;
};

# define SCENE typedef struct s_scene   Scene
# define FPS typedef struct s_fps       Fps
# define FLAGS typedef struct s_flags   Flags

SCENE;
FPS;
FLAGS;

struct	s_environment
{
	Sdl			*sdl;
	Scene		s;
	Isr			isr;
	Fps			fps;
	double_t	cam_speed;
	double_t	t_max;
	double_t	t_min;
	Flags		flags;
};

# define ENV typedef struct s_environment   Environment

ENV;

struct	s_calc_light_helper
{
	Vector		p;
	Vector		n;
	Vector		l;
	Vector		h;
	Vector		d;
	double_t	dnl;
	double_t	h_intense;
	double_t	i;
};

typedef struct s_calc_light_helper	t_clhelp;

struct	s_parse_file_helper
{
	uint16_t	nline;
	size_t		obj_counter;
	size_t		light_counter;
};

typedef struct s_parse_file_helper	t_pfhelp;

#endif
