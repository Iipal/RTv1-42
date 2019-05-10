/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:07:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/10 18:20:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_sdl_keys_press(Environment *env)
{
	if (SDLK_x == SEKEY)
		env->isr.is_debug = !env->isr.is_debug;
	if (SDLK_w == SEKEY)
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
	else if (SDLK_z == SEKEY)
		env->isr.is_render_fps = !env->isr.is_render_fps;
	else if (SDLK_LSHIFT == SEKEY)
		env->isr.is_speedup = true;
	else if (SDLK_LCTRL == SEKEY)
		env->isr.is_speeddown = true;
}

inline void	rt_sdl_keys_release(Environment *env)
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
