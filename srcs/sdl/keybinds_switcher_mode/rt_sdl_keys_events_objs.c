/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events_objs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 23:55:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/21 12:01:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	add_objs_z_or_spec(Object *const o,
									const Isr *const isr,
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

static inline void	add_objs_rot(Object *const o,
							const Fps *const fps,
							const Isr *const isr)
{
	if (isr->is_rot_x)
		X(o->dir) =
			X(o->dir) + fps->move >= 360 ? 0.0f : X(o->dir) + fps->move;
	if (isr->is_rot_y)
		Y(o->dir) =
			Y(o->dir) + fps->move >= 360 ? 0.0f : Y(o->dir) + fps->move;
	if (isr->is_rot_z)
		Z(o->dir) =
			Z(o->dir) + fps->move >= 360 ? 0.0f : Z(o->dir) + fps->move;
}

void				rt_sdl_keys_events_objs_debug(Object *const o,
												const Fps *const fps,
												const Isr *const isr,
												const size_t in_scene_objects)
{
	size_t	i;

	i = ~0L;
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
		add_objs_rot(&o[i], fps, isr);
	}
}
