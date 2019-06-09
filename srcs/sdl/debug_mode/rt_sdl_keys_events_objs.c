/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events_objs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 23:55:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/09 04:55:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline __attribute__((__always_inline__)) void	add_objs_z_or_spec(
	Object *restrict const o,
	const Isr *restrict const isr,
	const double_t move,
	const double_t s_move)
{
	if (!isr->is_debug_zorintens)
	{
		if (isr->is_zdec)
			Z(o->pos) = u_d_range(Z(o->pos) + move, MAX_Z, MIN_Z);
		if (isr->is_zinc)
			Z(o->pos) = u_d_range(Z(o->pos) - move, MAX_Z, MIN_Z);
	}
	else
	{
		if (isr->is_zdec)
			o->spec = u_d_range(o->spec - s_move, MAX_SPEC, MIN_SPEC);
		if (isr->is_zinc)
			o->spec = u_d_range(o->spec + s_move, MAX_SPEC, MIN_SPEC);
	}
}

static inline __attribute__((__always_inline__)) void	add_objs_rot(
	Object *restrict const o,
	const Isr *restrict const isr,
	const double_t move)
{
	if (isr->is_rot_x)
		X(o->dir) = u_d_range(X(o->dir) + (move / 5.0f), 360.0f, -360.0f);
	if (isr->is_rot_y)
		Y(o->dir) = u_d_range(Y(o->dir) + (move / 5.0f), 360.0f, -360.0f);
	if (isr->is_rot_z)
		Z(o->dir) = u_d_range(Z(o->dir) + (move / 5.0f), 360.0f, -360.0f);
	if (isr->is_dec_rot_x)
		X(o->dir) = u_d_range(X(o->dir) - (move / 5.0f), 360.0f, -360.0f);
	if (isr->is_dec_rot_y)
		Y(o->dir) = u_d_range(Y(o->dir) - (move / 5.0f), 360.0f, -360.0f);
	if (isr->is_dec_rot_z)
		Z(o->dir) = u_d_range(Z(o->dir) - (move / 5.0f), 360.0f, -360.0f);
}

void				rt_sdl_keys_events_objs_debug(Object *restrict const o,
												const Fps *restrict const fps,
												const Isr *restrict const isr,
												const size_t in_scene_objects)
{
	size_t	i;

	i = ~0UL;
	while (in_scene_objects > ++i)
	{
		if (isr->is_up)
			Y(o[i].pos) = u_d_range(Y(o[i].pos) - fps->move, MAX_Y, MIN_Y);
		if (isr->is_down)
			Y(o[i].pos) = u_d_range(Y(o[i].pos) + fps->move, MAX_Y, MIN_Y);
		if (isr->is_left)
			X(o[i].pos) = u_d_range(X(o[i].pos) - fps->move, MAX_X, MIN_X);
		if (isr->is_right)
			X(o[i].pos) = u_d_range(X(o[i].pos) + fps->move, MAX_X, MIN_X);
		add_objs_z_or_spec(&o[i], isr, fps->move, fps->o_spec_intens);
		add_objs_rot(&o[i], isr, fps->move);
	}
}
