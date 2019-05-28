/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:07:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/28 19:17:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	add_sdl_keys_rot_press(Isr *restrict const isr,
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

static inline void	add_sdl_keys_mode_switch(Isr *restrict const isr)
{
	if (isr->is_objs_debug)
		isr->is_objs_debug = false;
	else if (isr->is_light_debug)
		isr->is_objs_debug = true;
	else
		isr->is_light_debug = !isr->is_light_debug;
}

inline void			rt_sdl_keys_press(Isr *restrict const isr,
									const SDL_Keycode key)
{
	if (SDLK_x == key)
		add_sdl_keys_mode_switch(isr);
	else if (SDLK_c == key)
		isr->is_debug_zorintens = !isr->is_debug_zorintens;
	else if (SDLK_z == key)
		isr->is_render_fps = !isr->is_render_fps;
	else if (SDLK_w == key)
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
	else
		add_sdl_keys_rot_press(isr, key);
}

static inline void	add_sdl_keys_rot_release(Isr *restrict const isr,
									const SDL_Keycode key)
{
	if (SDLK_r == key)
		isr->is_rot_x = false;
	else if (SDLK_f == key)
		isr->is_rot_y = false;
	else if (SDLK_v == key)
		isr->is_rot_z = false;
	else if (SDLK_t == key)
		isr->is_dec_rot_x = false;
	else if (SDLK_g == key)
		isr->is_dec_rot_y = false;
	else if (SDLK_b == key)
		isr->is_dec_rot_z = false;
}

inline void			rt_sdl_keys_release(Isr *restrict const isr,
									const SDL_Keycode key)
{
	if (SDLK_w == key)
		isr->is_up = false;
	else if (SDLK_s == key)
		isr->is_down = false;
	else if (SDLK_a == key)
		isr->is_left = false;
	else if (SDLK_d == key)
		isr->is_right = false;
	else if (SDLK_q == key)
		isr->is_zdec = false;
	else if (SDLK_e == key)
		isr->is_zinc = false;
	else if (SDLK_LSHIFT == key)
		isr->is_speedup = false;
	else if (SDLK_LCTRL == key)
		isr->is_speeddown = false;
	else
		add_sdl_keys_rot_release(isr, key);
}
