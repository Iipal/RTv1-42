/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events_lights.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:15:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 14:01:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	add_light_zorintens(Light *restrict const l,
				double_t const move,
				double_t const l_move)
{
	if (!IS_BIT(g_isr_flags, ISR_DBG_Z_OR_INTENSE))
	{
		if (IS_BIT(g_isr_flags, ISR_ZDEC))
			Z(l->pos) = u_d_range(Z(l->pos) - move, MAX_Z, MIN_Z);
		if (IS_BIT(g_isr_flags, ISR_ZINC))
			Z(l->pos) = u_d_range(Z(l->pos) + move, MAX_Z, MIN_Z);
	}
	else
	{
		if (IS_BIT(g_isr_flags, ISR_ZDEC))
			l->intens = u_d_range(l->intens - l_move,
				MAX_L_INTENS, MIN_L_INTENS);
		if (IS_BIT(g_isr_flags, ISR_ZINC))
			l->intens = u_d_range(l->intens + l_move,
				MAX_L_INTENS, MIN_L_INTENS);
	}
}

void		rt_sdl_keys_events_lights_debug(Light *restrict const l,
				Fps const *restrict const fps,
				size_t const in_scene_lights)
{
	size_t	i;

	i = ~0UL;
	while (in_scene_lights > ++i)
	{
		if (IS_BIT(g_isr_flags, ISR_UP))
			Y(l[i].pos) = u_d_range(Y(l[i].pos) - fps->l_move, MAX_Y, MIN_Y);
		if (IS_BIT(g_isr_flags, ISR_DOWN))
			Y(l[i].pos) = u_d_range(Y(l[i].pos) + fps->l_move, MAX_Y, MIN_Y);
		if (IS_BIT(g_isr_flags, ISR_LEFT))
			X(l[i].pos) = u_d_range(X(l[i].pos) - fps->l_move, MAX_X, MIN_X);
		if (IS_BIT(g_isr_flags, ISR_RIGHT))
			X(l[i].pos) = u_d_range(X(l[i].pos) + fps->l_move, MAX_X, MIN_X);
		add_light_zorintens(&l[i], fps->l_move, fps->l_intens);
	}
}
