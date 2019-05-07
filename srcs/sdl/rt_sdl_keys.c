/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:07:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/07 11:45:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_sdl_keys_press(Environment *env)
{
	if (SDLK_w == SEKEY)
		env->isr.is_cam_up = true;
	else if (SDLK_s == SEKEY)
		env->isr.is_cam_down = true;
	else if (SDLK_a == SEKEY)
		env->isr.is_cam_left = true;
	else if (SDLK_d == SEKEY)
		env->isr.is_cam_right = true;
	else if (SDLK_MINUS == SEKEY)
		env->isr.is_cam_zdec = true;
	else if (SDLK_EQUALS == SEKEY)
		env->isr.is_cam_zinc = true;
	else if (SDLK_r == SEKEY)
		env->isr.is_render_fps = !env->isr.is_render_fps;
	else if (SDLK_LSHIFT == SEKEY)
		env->isr.is_cam_speedup = true;
	else if (SDLK_LCTRL == SEKEY)
		env->isr.is_cam_speeddown = true;
}

inline void	rt_sdl_keys_release(Environment *env)
{
	if (SDLK_w == SEKEY)
		env->isr.is_cam_up = false;
	else if (SDLK_s == SEKEY)
		env->isr.is_cam_down = false;
	else if (SDLK_a == SEKEY)
		env->isr.is_cam_left = false;
	else if (SDLK_d == SEKEY)
		env->isr.is_cam_right = false;
	else if (SDLK_MINUS == SEKEY)
		env->isr.is_cam_zdec = false;
	else if (SDLK_EQUALS == SEKEY)
		env->isr.is_cam_zinc = false;
	else if (SDLK_LSHIFT == SEKEY)
		env->isr.is_cam_speedup = false;
	else if (SDLK_LCTRL == SEKEY)
		env->isr.is_cam_speeddown = false;
}
