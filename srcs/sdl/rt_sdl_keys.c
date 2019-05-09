/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:07:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/09 12:25:37 by tmaluh           ###   ########.fr       */
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
	else if (SDLK_q == SEKEY)
		env->isr.is_render_fps = !env->isr.is_render_fps;
	else if (SDLK_LSHIFT == SEKEY)
		env->isr.is_cam_speedup = true;
	else if (SDLK_LCTRL == SEKEY)
		env->isr.is_cam_speeddown = true;
	else if ((env->isr.is_debug = true))
	{
		if (SDLK_t == SEKEY)
			env->s.l.pos[Y] -= 10;
		else if (SDLK_g == SEKEY)
			env->s.l.pos[Y] += 10;
		else if (SDLK_f == SEKEY)
			env->s.l.pos[X] -= 10;
		else if (SDLK_h == SEKEY)
			env->s.l.pos[X] += 10;
		else if (SDLK_r == SEKEY)
			env->s.l.pos[Z] -= 10;
		else if (SDLK_y == SEKEY)
			env->s.l.pos[Z] += 10;
		else if (SDLK_u == SEKEY)
			env->s.l.intens += 0.01f;
		else if (SDLK_j == SEKEY)
			env->s.l.intens -= 0.01f;
		if (1.0f <= env->s.l.intens)
			env->s.l.intens = 1.0f;
		else if (0.0f >= env->s.l.intens)
			env->s.l.intens = 0.0f;
	}
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
