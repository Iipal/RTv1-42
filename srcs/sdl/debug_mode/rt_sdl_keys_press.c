/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_press.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:07:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/11 12:55:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	s_sdl_key_press_rot(SDL_Keycode const key)
{
	if (SDLK_r == key)
		SET_BIT(g_isr_flags, ISR_ROT_X);
	else if (SDLK_f == key)
		SET_BIT(g_isr_flags, ISR_ROT_Y);
	else if (SDLK_v == key)
		SET_BIT(g_isr_flags, ISR_ROT_Z);
	else if (SDLK_t == key)
		SET_BIT(g_isr_flags, ISR_DEC_ROT_X);
	else if (SDLK_g == key)
		SET_BIT(g_isr_flags, ISR_DEC_ROT_Y);
	else if (SDLK_b == key)
		SET_BIT(g_isr_flags, ISR_DEC_ROT_Z);
}

void			rt_sdl_keys_press(SDL_Keycode const key)
{
	if (SDLK_w == key)
		SET_BIT(g_isr_flags, ISR_UP);
	else if (SDLK_s == key)
		SET_BIT(g_isr_flags, ISR_DOWN);
	else if (SDLK_a == key)
		SET_BIT(g_isr_flags, ISR_LEFT);
	else if (SDLK_d == key)
		SET_BIT(g_isr_flags, ISR_RIGHT);
	else if (SDLK_q == key)
		SET_BIT(g_isr_flags, ISR_ZDEC);
	else if (SDLK_e == key)
		SET_BIT(g_isr_flags, ISR_ZINC);
	else if (SDLK_LSHIFT == key)
		SET_BIT(g_isr_flags, ISR_SPEEDUP);
	else if (SDLK_LCTRL == key)
		SET_BIT(g_isr_flags, ISR_SPEEDDOWN);
	else if (SDLK_EQUALS == key)
		SET_BIT(g_isr_flags, ISR_INC_AL);
	else if (SDLK_MINUS == key)
		SET_BIT(g_isr_flags, ISR_DEC_AL);
	else
		s_sdl_key_press_rot(key);
}

void		rt_sdl_keys_press_switcher_mode(SDL_Keycode const key)
{

	if (SDLK_x == key)
	{
		if (IS_BIT(g_isr_flags, ISR_OBJS_DEBUG))
			UNSET_BIT(g_isr_flags, ISR_OBJS_DEBUG);
		else if (IS_BIT(g_isr_flags, ISR_LIGHT_DEBUG))
			SET_BIT(g_isr_flags, ISR_OBJS_DEBUG);
		else
			TOGGLE_BIT(g_isr_flags, ISR_LIGHT_DEBUG);
	}
	else if (SDLK_c == key)
		TOGGLE_BIT(g_isr_flags, ISR_DBG_Z_OR_INTENSE);
}

void		rt_sdl_keys_press_add_settings(SDL_Keycode const key)
{

	if (SDLK_z == key)
		TOGGLE_BIT(g_isr_flags, ISR_RENDER_FPS);
	else if (SDLK_h == key)
		TOGGLE_BIT(g_flags, F_BIT_SHADOWS);
	else if (SDLK_y == key)
		TOGGLE_BIT(g_flags, F_BIT_TEX);
	else if (SDLK_n == key)
		TOGGLE_BIT(g_flags, F_BIT_NCL);
	else if (SDLK_j == key)
		TOGGLE_BIT(g_flags, F_BIT_RLI);
}
