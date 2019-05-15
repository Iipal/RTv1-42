/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:12:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/15 10:41:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	add_camera_keys_events(Environment *env)
{
	if (env->isr.is_up)
		Y(env->s.cam.pos) = u_inranged(Y(env->s.cam.pos) - env->fps.move, 1, 0);
	if (env->isr.is_down)
		Y(env->s.cam.pos) = u_inranged(Y(env->s.cam.pos) + env->fps.move, 0, 1);
	if (env->isr.is_left)
		X(env->s.cam.pos) = u_inranged(X(env->s.cam.pos) - env->fps.move, 1, 0);
	if (env->isr.is_right)
		X(env->s.cam.pos) = u_inranged(X(env->s.cam.pos) + env->fps.move, 0, 1);
	if (env->isr.is_zdec)
		Z(env->s.cam.pos) = u_inranged(Z(env->s.cam.pos) - env->fps.move, 1, 0);
	if (env->isr.is_zinc)
		Z(env->s.cam.pos) = u_inranged(Z(env->s.cam.pos) + env->fps.move, 0, 1);
}

inline void			rt_sdl_keys_events(Environment *env)
{
	if (env->isr.is_light_debug)
		rt_sdl_keys_events_light_debug(env);
	else
		add_camera_keys_events(env);
	rt_camera_speed_movements(&env->cam_speed,
			env->isr.is_speedup, env->isr.is_speeddown);
}
