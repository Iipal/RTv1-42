/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events_objs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 23:55:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 23:51:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	rt_objs_z_or_spec(Environment *env, size_t i)
{
	if (!env->isr.is_debug_zorintens)
	{
		if (env->isr.is_zdec)
			Z(env->s.objs[i].pos) =
				u_inranged(Z(env->s.objs[i].pos) + env->fps.move, false, true);
		if (env->isr.is_zinc)
			Z(env->s.objs[i].pos) =
				u_inranged(Z(env->s.objs[i].pos) - env->fps.move, true, false);
	}
	else
	{
		if (env->isr.is_zdec)
			env->s.objs[i].spec =
				(MIN_SPEC > env->s.objs[i].spec - env->fps.objs_spec_intens)
				? MIN_SPEC : (env->s.objs[i].spec - env->fps.objs_spec_intens);
		if (env->isr.is_zinc)
			env->s.objs[i].spec =
				(MAX_SPEC < env->s.objs[i].spec + env->fps.objs_spec_intens)
				? MAX_SPEC : (env->s.objs[i].spec + env->fps.objs_spec_intens);
	}
}

void				rt_sdl_keys_events_objs_debug(Environment *env)
{
	size_t	i;

	i = ~0L;
	while (env->s.ins_objs > ++i)
	{
		if (env->isr.is_up)
			Y(env->s.objs[i].pos) =
				u_inranged(Y(env->s.objs[i].pos) - env->fps.move, true, false);
		if (env->isr.is_down)
			Y(env->s.objs[i].pos) =
				u_inranged(Y(env->s.objs[i].pos) + env->fps.move, false, true);
		if (env->isr.is_left)
			X(env->s.objs[i].pos) =
				u_inranged(X(env->s.objs[i].pos) - env->fps.move, true, false);
		if (env->isr.is_right)
			X(env->s.objs[i].pos) =
				u_inranged(X(env->s.objs[i].pos) + env->fps.move, false, true);
		rt_objs_z_or_spec(env, i);
	}
}
