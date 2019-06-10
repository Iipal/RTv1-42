/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_press.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:07:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/10 10:02:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline __attribute__((__always_inline__)) void	add_sdl_key_press_rot(
	Isr *restrict const isr,
	const SDL_Keycode key)
{
	if (SDLK_r == key)
		isr->is_rot_x = true;
	else if (SDLK_f == key)
		isr->is_rot_y = true;
	else if (SDLK_v == key)
		isr->is_rot_z = true;
	else if (SDLK_t == key)
		isr->is_dec_rot_x = true;
	else if (SDLK_g == key)
		isr->is_dec_rot_y = true;
	else if (SDLK_b == key)
		isr->is_dec_rot_z = true;
}

void				rt_sdl_keys_press(Isr *restrict const isr,
										const SDL_Keycode key)
{
	if (SDLK_w == key)
		isr->is_up = true;
	else if (SDLK_s == key)
		isr->is_down = true;
	else if (SDLK_a == key)
		isr->is_left = true;
	else if (SDLK_d == key)
		isr->is_right = true;
	else if (SDLK_q == key)
		isr->is_zdec = true;
	else if (SDLK_e == key)
		isr->is_zinc = true;
	else if (SDLK_LSHIFT == key)
		isr->is_speedup = true;
	else if (SDLK_LCTRL == key)
		isr->is_speeddown = true;
	else if (SDLK_EQUALS == key)
		isr->is_inc_ambient_light = true;
	else if (SDLK_MINUS == key)
		isr->is_dec_ambient_light = true;
	else
		add_sdl_key_press_rot(isr, key);
}

inline void			rt_sdl_keys_press_switcher_mode(Isr *restrict const isr,
										const SDL_Keycode key)
{
	if (SDLK_x == key)
	{
		if (isr->is_objs_debug)
			isr->is_objs_debug = false;
		else if (isr->is_light_debug)
			isr->is_objs_debug = true;
		else
			isr->is_light_debug = !isr->is_light_debug;
	}
	else if (SDLK_c == key)
		isr->is_debug_zorintens = !isr->is_debug_zorintens;
}

inline void			rt_sdl_keys_press_add_settings(
	Environment *restrict const env,
	const SDL_Keycode key)
{
	if (SDLK_z == key)
		env->isr.is_render_fps = !env->isr.is_render_fps;
	else if (SDLK_h == key)
		env->scene.is_render_shadow = !env->scene.is_render_shadow;
	else if (SDLK_y == key)
		env->flags.textured = !env->flags.textured;
	else if (SDLK_n == key)
		env->flags.no_calc_light = !env->flags.no_calc_light;
	else if (SDLK_j == key)
		env->flags.random_lights_intense = !env->flags.random_lights_intense;
}
