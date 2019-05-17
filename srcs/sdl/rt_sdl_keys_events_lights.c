/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events_lights.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:15:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 11:20:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	rt_light_zorintens(Environment *env, size_t i)
{
	if (!env->isr.is_debug_zorintens)
	{
		if (env->isr.is_zdec)
			Z(env->s.l[i].pos) =
				u_inranged(Z(env->s.l[i].pos) - env->fps.move * 5, 1, 0);
		if (env->isr.is_zinc)
			Z(env->s.l[i].pos) =
				u_inranged(Z(env->s.l[i].pos) + env->fps.move * 5, 0, 1);
	}
	else
	{
		if (env->isr.is_zdec)
			env->s.l[i].intens = (0.0f > env->s.l[i].intens - env->fps.move / 2)
				? 0.0f : (env->s.l[i].intens - env->fps.move / 2);
		if (env->isr.is_zinc)
			env->s.l[i].intens = (1.0f < env->s.l[i].intens + env->fps.move / 2)
				? 1.0f : (env->s.l[i].intens + env->fps.move / 2);
	}
}

void				rt_sdl_keys_events_light_debug(Environment *env)
{
	size_t	i;

	i = ~0L;
	while (env->s.ins_l > ++i)
	{
		if (env->isr.is_up)
			Y(env->s.l[i].pos) =
				u_inranged(Y(env->s.l[i].pos) - env->fps.move * 5, 1, 0);
		if (env->isr.is_down)
			Y(env->s.l[i].pos) =
				u_inranged(Y(env->s.l[i].pos) + env->fps.move * 5, 0, 1);
		if (env->isr.is_left)
			X(env->s.l[i].pos) =
				u_inranged(X(env->s.l[i].pos) - env->fps.move * 5, 1, 0);
		if (env->isr.is_right)
			X(env->s.l[i].pos) =
				u_inranged(X(env->s.l[i].pos) + env->fps.move * 5, 0, 1);
		rt_light_zorintens(env, i);
	}
}
