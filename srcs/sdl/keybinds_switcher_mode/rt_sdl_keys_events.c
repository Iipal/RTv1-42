/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:12:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/28 19:12:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	add_camera_keys_events(const Isr *restrict const isr,
										Camera *restrict const cam,
										const double_t move)
{
	if (isr->is_up)
		Y(cam->pos) = u_d_range(Y(cam->pos) - move, MAX_Y, MIN_Y);
	if (isr->is_down)
		Y(cam->pos) = u_d_range(Y(cam->pos) + move, MAX_Y, MIN_Y);
	if (isr->is_left)
		X(cam->pos) = u_d_range(X(cam->pos) - move, MAX_X, MIN_X);
	if (isr->is_right)
		X(cam->pos) = u_d_range(X(cam->pos) + move, MAX_X, MIN_X);
	if (isr->is_zdec)
		Z(cam->pos) = u_d_range(Z(cam->pos) - move, MAX_Z, MIN_Z);
	if (isr->is_zinc)
		Z(cam->pos) = u_d_range(Z(cam->pos) + move, MAX_Z, MIN_Z);
	if (isr->is_rot_x)
		X(cam->dir) = u_d_range(X(cam->dir) + (move * 2), 360.0f, -360.0f);
	if (isr->is_rot_y)
		Y(cam->dir) = u_d_range(Y(cam->dir) + (move * 2), 360.0f, -360.0f);
	if (isr->is_rot_z)
		Z(cam->dir) = u_d_range(Z(cam->dir) + (move * 2), 360.0f, -360.0f);
	if (isr->is_dec_rot_x)
		X(cam->dir) = u_d_range(X(cam->dir) - (move * 2), 360.0f, -360.0f);
	if (isr->is_dec_rot_y)
		Y(cam->dir) = u_d_range(Y(cam->dir) - (move * 2), 360.0f, -360.0f);
	if (isr->is_dec_rot_z)
		Z(cam->dir) = u_d_range(Z(cam->dir) - (move * 2), 360.0f, -360.0f);
}

inline void			rt_sdl_keys_events(Environment *restrict const env)
{
	if (env->isr.is_light_debug)
	{
		if (env->isr.is_objs_debug)
			env->isr.is_light_debug = false;
		else if (!env->flags.no_calc_light)
			rt_sdl_keys_events_lights_debug(env->scene.lights,
				&env->fps, &env->isr, env->scene.ins_lights);
	}
	else if (env->isr.is_objs_debug)
		rt_sdl_keys_events_objs_debug(env->scene.objs,
			&env->fps, &env->isr, env->scene.ins_objs);
	else
		add_camera_keys_events(&env->isr, &env->scene.cam, env->fps.move);
	rt_camera_speed_movements(&env->cam_speed,
			env->isr.is_speedup, env->isr.is_speeddown);
}
