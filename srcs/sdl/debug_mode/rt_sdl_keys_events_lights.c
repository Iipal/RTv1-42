/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events_lights.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:15:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/09 04:55:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline __attribute__((__always_inline__)) void	add_light_zorintens(
	Light *restrict const l,
	const Isr *restrict const isr,
	const double_t move,
	const double_t l_move)
{
	if (!isr->is_debug_zorintens)
	{
		if (isr->is_zdec)
			Z(l->pos) = u_d_range(Z(l->pos) - move, MAX_Z, MIN_Z);
		if (isr->is_zinc)
			Z(l->pos) = u_d_range(Z(l->pos) + move, MAX_Z, MIN_Z);
	}
	else
	{
		if (isr->is_zdec)
			l->intens = u_d_range(l->intens - l_move,
				MAX_L_INTENS, MIN_L_INTENS);
		if (isr->is_zinc)
			l->intens = u_d_range(l->intens + l_move,
				MAX_L_INTENS, MIN_L_INTENS);
	}
}

void				rt_sdl_keys_events_lights_debug(Light *restrict const l,
												const Fps *restrict const fps,
												const Isr *restrict const isr,
												const size_t in_scene_lights)
{
	size_t	i;

	i = ~0UL;
	while (in_scene_lights > ++i)
	{
		if (isr->is_up)
			Y(l[i].pos) = u_d_range(Y(l[i].pos) - fps->l_move, MAX_Y, MIN_Y);
		if (isr->is_down)
			Y(l[i].pos) = u_d_range(Y(l[i].pos) + fps->l_move, MAX_Y, MIN_Y);
		if (isr->is_left)
			X(l[i].pos) = u_d_range(X(l[i].pos) - fps->l_move, MAX_X, MIN_X);
		if (isr->is_right)
			X(l[i].pos) = u_d_range(X(l[i].pos) + fps->l_move, MAX_X, MIN_X);
		add_light_zorintens(&l[i], isr, fps->l_move, fps->l_intens);
	}
}
