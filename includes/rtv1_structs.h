/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:09:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/17 00:44:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTS_H
# define RTV1_STRUCTS_H

# include "rtv1_scene_structs.h"

struct	s_isrender
{
	bool	is_up:1;
	bool	is_down:1;
	bool	is_left:1;
	bool	is_right:1;
	bool	is_zinc:1;
	bool	is_zdec:1;
	bool	is_rot_x:1;
	bool	is_rot_y:1;
	bool	is_rot_z:1;
	bool	is_dec_rot_x:1;
	bool	is_dec_rot_y:1;
	bool	is_dec_rot_z:1;
	bool	is_render_fps:1;
	bool	is_speedup:1;
	bool	is_speeddown:1;
	bool	is_light_debug:1;
	bool	is_objs_debug:1;
	bool	is_debug_zorintens:1;
	bool	is_inc_ambient_light:1;
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
	Color	fps_text_color;
	float_t	fps_refresh_timer;
	float_t	viewport_scale;
	float_t	ambient_light;
	uint8_t	anti_aliasing;
	bool	is_parsed_ftc:1;
	bool	is_parsed_frt:1;
	bool	is_parsed_vps:1;
	bool	is_parsed_al:1;
	bool	is_parsed_aa:1;
	bool	debug_mode:1;
	bool	no_calc_light:1;
	bool	textured:1;
	bool	random_lights_intense;
	bool	print_usage;
};

# define FLAGS typedef struct s_flags Flags

FLAGS;

struct	s_environment
{
	__v4df		**pre_calc_d;
	Sdl			*sdl;
	double_t	cam_speed;
	double_t	tmax;
	double_t	tmin;
	Fps			fps;
	Isr			isr;
	Scene		scene;
	Flags		flags;
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
