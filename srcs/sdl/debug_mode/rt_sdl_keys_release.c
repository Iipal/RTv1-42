/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:30:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/10 10:02:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline __attribute__((__always_inline__)) void	add_sdl_key_rot_rls(
	Isr *restrict const isr,
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

void				rt_sdl_keys_release(Isr *restrict const isr,
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
	else if (SDLK_EQUALS == key)
		isr->is_inc_ambient_light = false;
	else if (SDLK_MINUS == key)
		isr->is_dec_ambient_light = false;
	else
		add_sdl_key_rot_rls(isr, key);
}
