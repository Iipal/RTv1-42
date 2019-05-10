/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:12:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/10 18:24:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	add_light_debug_key_events(Environment *env)
{
	if (env->isr.is_up)
		env->s.l.pos[Y] = u_inrangev(env->s.l.pos[Y] - env->fps.move * 5, 1, 0);
	if (env->isr.is_down)
		env->s.l.pos[Y] = u_inrangev(env->s.l.pos[Y] + env->fps.move * 5, 0, 1);
	if (env->isr.is_left)
		env->s.l.pos[X] = u_inrangev(env->s.l.pos[X] - env->fps.move * 5, 1, 0);
	if (env->isr.is_right)
		env->s.l.pos[X] = u_inrangev(env->s.l.pos[X] + env->fps.move * 5, 0, 1);
	if (env->isr.is_zdec)
		env->s.l.intens = 0.0f > env->s.l.intens - 0.015f
			? 0.0f : env->s.l.intens - 0.015f;
	if (env->isr.is_zinc)
		env->s.l.intens = 1.0f < env->s.l.intens + 0.015f
			? 1.0f : env->s.l.intens + 0.015f;
}

static inline void	add_normal_keys_events(Environment *env)
{
	if (env->isr.is_up)
		env->s.cam.pos[Y] = u_inrangev(env->s.cam.pos[Y] - env->fps.move, 1, 0);
	if (env->isr.is_down)
		env->s.cam.pos[Y] = u_inrangev(env->s.cam.pos[Y] + env->fps.move, 0, 1);
	if (env->isr.is_left)
		env->s.cam.pos[X] = u_inrangev(env->s.cam.pos[X] - env->fps.move, 1, 0);
	if (env->isr.is_right)
		env->s.cam.pos[X] = u_inrangev(env->s.cam.pos[X] + env->fps.move, 0, 1);
	if (env->isr.is_zdec)
		env->s.cam.pos[Z] = u_inrangev(env->s.cam.pos[Z] - env->fps.move, 1, 0);
	if (env->isr.is_zinc)
		env->s.cam.pos[Z] = u_inrangev(env->s.cam.pos[Z] + env->fps.move, 0, 1);
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
