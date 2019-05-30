/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:09:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/31 00:53:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTS_H
# define RTV1_STRUCTS_H

# include "rtv1_scene.h"
# include "rtv1_flags.h"

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

# define FPS typedef struct s_fps       Fps

FPS;

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
};

# define ENV typedef struct s_environment   Environment

ENV;

struct	s_calc_light_helper
{
	Vector		p;
	Vector		n;
	Vector		l;
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
