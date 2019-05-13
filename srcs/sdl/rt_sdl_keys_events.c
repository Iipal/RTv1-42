/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:12:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/13 12:11:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	add_light_debug_key_events(Environment *env)
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
		if (env->isr.is_zdec)
			env->s.l[i].intens = 0.0f > env->s.l[i].intens - 0.015f
				? 0.0f : env->s.l[i].intens - 0.015f;
		if (env->isr.is_zinc)
			env->s.l[i].intens = 1.0f < env->s.l[i].intens + 0.015f
				? 1.0f : env->s.l[i].intens + 0.015f;
	}
}

static inline void	add_normal_keys_events(Environment *env)
{
	if (env->isr.is_up)
		Y(env->s.cam.pos) = u_inrangev(Y(env->s.cam.pos) - env->fps.move, 1, 0);
	if (env->isr.is_down)
		Y(env->s.cam.pos) = u_inrangev(Y(env->s.cam.pos) + env->fps.move, 0, 1);
	if (env->isr.is_left)
		X(env->s.cam.pos) = u_inrangev(X(env->s.cam.pos) - env->fps.move, 1, 0);
	if (env->isr.is_right)
		X(env->s.cam.pos) = u_inrangev(X(env->s.cam.pos) + env->fps.move, 0, 1);
	if (env->isr.is_zdec)
		Z(env->s.cam.pos) = u_inrangev(Z(env->s.cam.pos) - env->fps.move, 1, 0);
	if (env->isr.is_zinc)
		Z(env->s.cam.pos) = u_inrangev(Z(env->s.cam.pos) + env->fps.move, 0, 1);
}

inline void			rt_sdl_keys_events(Environment *env)
{
	if (env->isr.is_debug)
		add_light_debug_key_events(env);
	else
		add_normal_keys_events(env);
	rt_camera_speed_movements(&env->cam_speed,
			env->isr.is_speedup, env->isr.is_speeddown);
}
