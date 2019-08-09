/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:30:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/08 23:35:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	add_sdl_key_rot_release(SDL_Keycode const key)
{
	if (SDLK_r == key)
		UNSET_BIT(g_isr_flags, ISR_ROT_X);
	else if (SDLK_f == key)
		UNSET_BIT(g_isr_flags, ISR_ROT_Y);
	else if (SDLK_v == key)
		UNSET_BIT(g_isr_flags, ISR_ROT_Z);
	else if (SDLK_t == key)
		UNSET_BIT(g_isr_flags, ISR_DEC_ROT_X);
	else if (SDLK_g == key)
		UNSET_BIT(g_isr_flags, ISR_DEC_ROT_Y);
	else if (SDLK_b == key)
		UNSET_BIT(g_isr_flags, ISR_DEC_ROT_Z);
}

void		rt_sdl_keys_release(SDL_Keycode const key)
{
	if (SDLK_w == key)
		UNSET_BIT(g_isr_flags, ISR_UP);
	else if (SDLK_s == key)
		UNSET_BIT(g_isr_flags, ISR_DOWN);
	else if (SDLK_a == key)
		UNSET_BIT(g_isr_flags, ISR_LEFT);
	else if (SDLK_d == key)
		UNSET_BIT(g_isr_flags, ISR_RIGHT);
	else if (SDLK_q == key)
		UNSET_BIT(g_isr_flags, ISR_ZDEC);
	else if (SDLK_e == key)
		UNSET_BIT(g_isr_flags, ISR_ZINC);
	else if (SDLK_LSHIFT == key)
		UNSET_BIT(g_isr_flags, ISR_SPEEDUP);
	else if (SDLK_LCTRL == key)
		UNSET_BIT(g_isr_flags, ISR_SPEEDDOWN);
	else if (SDLK_EQUALS == key)
		UNSET_BIT(g_isr_flags, ISR_INC_AL);
	else if (SDLK_MINUS == key)
		UNSET_BIT(g_isr_flags, ISR_DEC_AL);
	else
		add_sdl_key_rot_release(key);
}
