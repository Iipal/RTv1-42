/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events_light.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:15:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 18:19:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	rt_light_z_or_intens(Environment *env, size_t i)
{
	if (env->isr.is_zmove_light)
	{
		if (env->isr.is_zdec)
			Z(env->s.l[i].pos) =
				u_inrangev(Z(env->s.l[i].pos) - env->fps.move * 5, 0, 1);
		if (env->isr.is_zinc)
			Z(env->s.l[i].pos) =
				u_inrangev(Z(env->s.l[i].pos) + env->fps.move * 5, 0, 1);
	}
	else
	{
		if (env->isr.is_zdec)
			env->s.l[i].intens = 0.0f > env->s.l[i].intens - 0.015f
				? 0.0f : env->s.l[i].intens - 0.015f;
		if (env->isr.is_zinc)
			env->s.l[i].intens = 1.0f < env->s.l[i].intens + 0.015f
				? 1.0f : env->s.l[i].intens + 0.015f;
	}
}

inline void			rt_sdl_keys_events_light_debug(Environment *env)
{
	size_t	i;

	i = ~0L;
	while (env->s.ins_l > ++i)
	{
		if (env->isr.is_up)
			Y(env->s.l[i].pos) =
				u_inrangev(Y(env->s.l[i].pos) - env->fps.move * 5, 1, 0);
		if (env->isr.is_down)
			Y(env->s.l[i].pos) =
				u_inrangev(Y(env->s.l[i].pos) + env->fps.move * 5, 0, 1);
		if (env->isr.is_left)
			X(env->s.l[i].pos) =
				u_inrangev(X(env->s.l[i].pos) - env->fps.move * 5, 1, 0);
		if (env->isr.is_right)
			X(env->s.l[i].pos) =
				u_inrangev(X(env->s.l[i].pos) + env->fps.move * 5, 0, 1);
		rt_light_z_or_intens(env, i);
	}
}
