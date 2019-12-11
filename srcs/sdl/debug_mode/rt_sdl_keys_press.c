/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_press.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:07:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/11 11:36:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	s_sdl_key_press_rot(SDL_Keycode const key)
{
	if (SDLK_r == key)
		return (SET_BIT(g_isr_flags, ISR_ROT_X));
	else if (SDLK_f == key)
		return (SET_BIT(g_isr_flags, ISR_ROT_Y));
	else if (SDLK_v == key)
		return (SET_BIT(g_isr_flags, ISR_ROT_Z));
	else if (SDLK_t == key)
		return (SET_BIT(g_isr_flags, ISR_DEC_ROT_X));
	else if (SDLK_g == key)
		return (SET_BIT(g_isr_flags, ISR_DEC_ROT_Y));
	else if (SDLK_b == key)
		return (SET_BIT(g_isr_flags, ISR_DEC_ROT_Z));
	return (0);
}

int			rt_sdl_keys_press(SDL_Keycode const key)
{
	if (SDLK_w == key)
		return (SET_BIT(g_isr_flags, ISR_UP));
	else if (SDLK_s == key)
		return (SET_BIT(g_isr_flags, ISR_DOWN));
	else if (SDLK_a == key)
		return (SET_BIT(g_isr_flags, ISR_LEFT));
	else if (SDLK_d == key)
		return (SET_BIT(g_isr_flags, ISR_RIGHT));
	else if (SDLK_q == key)
		return (SET_BIT(g_isr_flags, ISR_ZDEC));
	else if (SDLK_e == key)
		return (SET_BIT(g_isr_flags, ISR_ZINC));
	else if (SDLK_LSHIFT == key)
		return (SET_BIT(g_isr_flags, ISR_SPEEDUP));
	else if (SDLK_LCTRL == key)
		return (SET_BIT(g_isr_flags, ISR_SPEEDDOWN));
	else if (SDLK_EQUALS == key)
		return (SET_BIT(g_isr_flags, ISR_INC_AL));
	else if (SDLK_MINUS == key)
		return (SET_BIT(g_isr_flags, ISR_DEC_AL));
	return (s_sdl_key_press_rot(key));
}

int		rt_sdl_keys_press_switcher_mode(SDL_Keycode const key)
{
	int	ret;

	ret = 0;
	if (SDLK_x == key && (ret = 1))
	{
		if (IS_BIT(g_isr_flags, ISR_OBJS_DEBUG))
			UNSET_BIT(g_isr_flags, ISR_OBJS_DEBUG);
		else if (IS_BIT(g_isr_flags, ISR_LIGHT_DEBUG))
			SET_BIT(g_isr_flags, ISR_OBJS_DEBUG);
		else
			TOGGLE_BIT(g_isr_flags, ISR_LIGHT_DEBUG);
	}
	else if (SDLK_c == key && (ret = 1))
		TOGGLE_BIT(g_isr_flags, ISR_DBG_Z_OR_INTENSE);
	return (ret);
}

int		rt_sdl_keys_press_add_settings(SDL_Keycode const key)
{
	int	ret;

	ret = 0;
	if (SDLK_z == key && (ret = 1))
		TOGGLE_BIT(g_isr_flags, ISR_RENDER_FPS);
	else if (SDLK_h == key && (ret = 1))
		TOGGLE_BIT(g_flags, F_BIT_SHADOWS);
	else if (SDLK_y == key && (ret = 1))
		TOGGLE_BIT(g_flags, F_BIT_TEX);
	else if (SDLK_n == key && (ret = 1))
		TOGGLE_BIT(g_flags, F_BIT_NCL);
	else if (SDLK_j == key && (ret = 1))
		TOGGLE_BIT(g_flags, F_BIT_RLI);
	return (ret);
}
