/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:09:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/12 18:53:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTS_H
# define RTV1_STRUCTS_H

# include "rtv1_scene.h"

struct	s_isrender
{
	bool	is_up;
	bool	is_down;
	bool	is_left;
	bool	is_right;
	bool	is_zinc;
	bool	is_zdec;
	bool	is_rot_x;
	bool	is_rot_y;
	bool	is_rot_z;
	bool	is_dec_rot_x;
	bool	is_dec_rot_y;
	bool	is_dec_rot_z;
	bool	is_render_fps;
	bool	is_speedup;
	bool	is_speeddown;
	bool	is_light_debug;
	bool	is_objs_debug;
	bool	is_debug_zorintens;
	bool	is_inc_ambient_light;
	bool	is_dec_ambient_light;
};

struct	s_time
{
	float_t	old;
	float_t	current;
	float_t	res;
	float_t	ms;
	float_t	fps;
};

struct	s_fps
{
	Time		time;
	double_t	move;
	double_t	l_move;
	double_t	l_intens;
	double_t	o_spec_intens;
};

# define FPS typedef struct s_fps Fps

FPS;

struct	s_flags
{
	float_t	viewport_scale;
	bool	is_parsed_vps;
	double	ambient_light;
	bool	is_parsed_al;
	Color	fps_text_color;
	bool	is_parsed_ftc;
	float_t	fps_refresh_timer;
	bool	is_parsed_frt;
	bool	debug_mode;
	bool	no_calc_light;
	bool	textured;
	bool	random_lights_intense;
	bool	print_usage;
};

# define FLAGS typedef struct s_flags Flags

FLAGS;

struct	s_environment
{
	Sdl			*sdl;
	Scene		scene;
	Isr			isr;
	Fps			fps;
	double_t	cam_speed;
	double_t	tmax;
	double_t	tmin;
	Flags		flags;
	__v4df		**pre_calc_d;
};

# define ENV typedef struct s_environment Environment

ENV;

/*
**	Helper structs: (for above norme42)
*/
struct	s_calc_light_helper
{
	__v4df		p;
	__v4df		n;
	__v4df		l;
	double_t	i;
	Color		curr_clr;
	double_t	obj_spec;
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
