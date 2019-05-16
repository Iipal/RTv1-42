/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:07:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 00:41:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	add_sdl_keys_mode_switch(Environment *env)
{
	if (env->isr.is_objs_debug)
		env->isr.is_objs_debug = false;
	else if (env->isr.is_light_debug)
		env->isr.is_objs_debug = true;
	else
		env->isr.is_light_debug = !env->isr.is_light_debug;
}

inline void			rt_sdl_keys_press(Environment *env)
{
	if (SDLK_x == SEKEY)
		add_sdl_keys_mode_switch(env);
	else if (SDLK_c == SEKEY)
		env->isr.is_debug_zorintens = !env->isr.is_debug_zorintens;
	else if (SDLK_z == SEKEY)
		env->isr.is_render_fps = !env->isr.is_render_fps;
	else if (SDLK_w == SEKEY)
		env->isr.is_up = true;
	else if (SDLK_s == SEKEY)
		env->isr.is_down = true;
	else if (SDLK_a == SEKEY)
		env->isr.is_left = true;
	else if (SDLK_d == SEKEY)
		env->isr.is_right = true;
	else if (SDLK_q == SEKEY)
		env->isr.is_zdec = true;
	else if (SDLK_e == SEKEY)
		env->isr.is_zinc = true;
	else if (SDLK_LSHIFT == SEKEY)
		env->isr.is_speedup = true;
	else if (SDLK_LCTRL == SEKEY)
		env->isr.is_speeddown = true;
}

inline void			rt_sdl_keys_release(Environment *env)
{
	if (SDLK_w == SEKEY)
		env->isr.is_up = false;
	else if (SDLK_s == SEKEY)
		env->isr.is_down = false;
	else if (SDLK_a == SEKEY)
		env->isr.is_left = false;
	else if (SDLK_d == SEKEY)
		env->isr.is_right = false;
	else if (SDLK_q == SEKEY)
		env->isr.is_zdec = false;
	else if (SDLK_e == SEKEY)
		env->isr.is_zinc = false;
	else if (SDLK_LSHIFT == SEKEY)
		env->isr.is_speedup = false;
	else if (SDLK_LCTRL == SEKEY)
		env->isr.is_speeddown = false;
}
