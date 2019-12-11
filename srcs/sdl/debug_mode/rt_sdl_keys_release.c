/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:30:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/11 11:40:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	s_sdl_key_rot_release(SDL_Keycode const key)
{
	if (SDLK_r == key)
		return (UNSET_BIT(g_isr_flags, ISR_ROT_X));
	else if (SDLK_f == key)
		return (UNSET_BIT(g_isr_flags, ISR_ROT_Y));
	else if (SDLK_v == key)
		return (UNSET_BIT(g_isr_flags, ISR_ROT_Z));
	else if (SDLK_t == key)
		return (UNSET_BIT(g_isr_flags, ISR_DEC_ROT_X));
	else if (SDLK_g == key)
		return (UNSET_BIT(g_isr_flags, ISR_DEC_ROT_Y));
	else if (SDLK_b == key)
		return (UNSET_BIT(g_isr_flags, ISR_DEC_ROT_Z));
	return (0);
}

int		rt_sdl_keys_release(SDL_Keycode const key)
{
	if (SDLK_w == key)
		return (!UNSET_BIT(g_isr_flags, ISR_UP));
	else if (SDLK_s == key)
		return (!UNSET_BIT(g_isr_flags, ISR_DOWN));
	else if (SDLK_a == key)
		return (!UNSET_BIT(g_isr_flags, ISR_LEFT));
	else if (SDLK_d == key)
		return (!UNSET_BIT(g_isr_flags, ISR_RIGHT));
	else if (SDLK_q == key)
		return (!UNSET_BIT(g_isr_flags, ISR_ZDEC));
	else if (SDLK_e == key)
		return (!UNSET_BIT(g_isr_flags, ISR_ZINC));
	else if (SDLK_LSHIFT == key)
		return (!UNSET_BIT(g_isr_flags, ISR_SPEEDUP));
	else if (SDLK_LCTRL == key)
		return (!UNSET_BIT(g_isr_flags, ISR_SPEEDDOWN));
	else if (SDLK_EQUALS == key)
		return (!UNSET_BIT(g_isr_flags, ISR_INC_AL));
	else if (SDLK_MINUS == key)
		return (!UNSET_BIT(g_isr_flags, ISR_DEC_AL));
	return (!s_sdl_key_rot_release(key));
}
