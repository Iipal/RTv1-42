/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:09:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/09/02 21:51:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTS_H
# define RTV1_STRUCTS_H

# include "rtv1_scene_structs.h"

struct	s_time
{
	float_t	old;
	float_t	current;
	float_t	res;
};

struct	s_fps
{
	Time		time;
	double_t	move;
	double_t	l_move;
	double_t	l_intens;
	double_t	o_spec_intens;
};

struct	s_fps_render
{
	char	*fps_str;
	char	*ms_str;
	float_t	fps;
	float_t	ms;
	float_t	frt_delta;
};

struct	s_flags
{
	Color	fps_text_color;
	float_t	fps_refresh_timer;
	float_t	viewport_scale;
	float_t	ambient_light;
	uint8_t	anti_aliasing;
};

# define FPS typedef struct s_fps Fps
# define FPS_R typedef struct s_fps_render FpsRenderHelper
# define FLAGS typedef struct s_flags Flags

FPS;
FPS_R;
FLAGS;

struct	s_environment
{
	t_v4df			**pre_calc_d;
	Sdl				*sdl;
	FpsRenderHelper	*frh;
	Fps				fps;
	double_t		cam_speed;
	Scene			scene;
	Flags			flags;
};

# define ENV typedef struct s_environment Environment

ENV;

/*
**	Helper structs: (for above norme42)
*/
struct	s_calc_light_helper
{
	t_v4df		p;
	t_v4df		n;
	t_v4df		l;
	Color		curr_clr;
	double_t	i;
	double_t	obj_spec;
	float_t		al;
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
