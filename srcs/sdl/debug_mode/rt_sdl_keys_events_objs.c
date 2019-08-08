/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events_objs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 23:55:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/08 23:39:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	add_objs_z_or_spec(Object *restrict const o,
				double_t const move,
				double_t const s_move)
{
	if (!IS_BIT(g_isr_flags, ISR_DBG_Z_OR_INTENSE))
	{
		if (IS_BIT(g_isr_flags, ISR_ZDEC))
			Z(o->pos) = u_d_range(Z(o->pos) + move, MAX_Z, MIN_Z);
		if (IS_BIT(g_isr_flags, ISR_ZINC))
			Z(o->pos) = u_d_range(Z(o->pos) - move, MAX_Z, MIN_Z);
	}
	else
	{
		if (IS_BIT(g_isr_flags, ISR_ZDEC))
			o->spec = u_d_range(o->spec - s_move, MAX_SPEC, MIN_SPEC);
		if (IS_BIT(g_isr_flags, ISR_ZINC))
			o->spec = u_d_range(o->spec + s_move, MAX_SPEC, MIN_SPEC);
	}
}

static void	add_objs_rot(Object *restrict const o, double_t const move)
{
	if (IS_BIT(g_isr_flags, ISR_ROT_X))
		X(o->dir) = u_d_range(X(o->dir) + (move / 5.0f), 360.0f, -360.0f);
	if (IS_BIT(g_isr_flags, ISR_ROT_Y))
		Y(o->dir) = u_d_range(Y(o->dir) + (move / 5.0f), 360.0f, -360.0f);
	if (IS_BIT(g_isr_flags, ISR_ROT_Z))
		Z(o->dir) = u_d_range(Z(o->dir) + (move / 5.0f), 360.0f, -360.0f);
	if (IS_BIT(g_isr_flags, ISR_DEC_ROT_X))
		X(o->dir) = u_d_range(X(o->dir) - (move / 5.0f), 360.0f, -360.0f);
	if (IS_BIT(g_isr_flags, ISR_DEC_ROT_Y))
		Y(o->dir) = u_d_range(Y(o->dir) - (move / 5.0f), 360.0f, -360.0f);
	if (IS_BIT(g_isr_flags, ISR_DEC_ROT_Z))
		Z(o->dir) = u_d_range(Z(o->dir) - (move / 5.0f), 360.0f, -360.0f);
}

void		rt_sdl_keys_events_objs_debug(Object *restrict const o,
				Fps const *restrict const fps,
				size_t const in_scene_objects)
{
	size_t	i;

	i = ~0UL;
	while (in_scene_objects > ++i)
	{
		if (IS_BIT(g_isr_flags, ISR_UP))
			Y(o[i].pos) = u_d_range(Y(o[i].pos) - fps->move, MAX_Y, MIN_Y);
		if (IS_BIT(g_isr_flags, ISR_DOWN))
			Y(o[i].pos) = u_d_range(Y(o[i].pos) + fps->move, MAX_Y, MIN_Y);
		if (IS_BIT(g_isr_flags, ISR_LEFT))
			X(o[i].pos) = u_d_range(X(o[i].pos) - fps->move, MAX_X, MIN_X);
		if (IS_BIT(g_isr_flags, ISR_RIGHT))
			X(o[i].pos) = u_d_range(X(o[i].pos) + fps->move, MAX_X, MIN_X);
		add_objs_z_or_spec(&o[i], fps->move, fps->o_spec_intens);
		add_objs_rot(&o[i], fps->move);
	}
}
