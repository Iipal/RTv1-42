/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:12:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/08 23:47:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	add_camera_events(Camera *restrict const cam, double_t const move)
{
	if (IS_BIT(g_isr_flags, ISR_UP))
		Y(cam->pos) = u_d_range(Y(cam->pos) - move, MAX_Y, MIN_Y);
	if (IS_BIT(g_isr_flags, ISR_DOWN))
		Y(cam->pos) = u_d_range(Y(cam->pos) + move, MAX_Y, MIN_Y);
	if (IS_BIT(g_isr_flags, ISR_LEFT))
		X(cam->pos) = u_d_range(X(cam->pos) - move, MAX_X, MIN_X);
	if (IS_BIT(g_isr_flags, ISR_RIGHT))
		X(cam->pos) = u_d_range(X(cam->pos) + move, MAX_X, MIN_X);
	if (IS_BIT(g_isr_flags, ISR_ZDEC))
		Z(cam->pos) = u_d_range(Z(cam->pos) - move, MAX_Z, MIN_Z);
	if (IS_BIT(g_isr_flags, ISR_ZINC))
		Z(cam->pos) = u_d_range(Z(cam->pos) + move, MAX_Z, MIN_Z);
	if (IS_BIT(g_isr_flags, ISR_ROT_X))
		X(cam->dir) = u_d_range(X(cam->dir) + (move * 2), 360.0f, -360.0f);
	if (IS_BIT(g_isr_flags, ISR_ROT_Y))
		Y(cam->dir) = u_d_range(Y(cam->dir) + (move * 2), 360.0f, -360.0f);
	if (IS_BIT(g_isr_flags, ISR_ROT_Z))
		Z(cam->dir) = u_d_range(Z(cam->dir) + (move * 2), 360.0f, -360.0f);
	if (IS_BIT(g_isr_flags, ISR_DEC_ROT_X))
		X(cam->dir) = u_d_range(X(cam->dir) - (move * 2), 360.0f, -360.0f);
	if (IS_BIT(g_isr_flags, ISR_DEC_ROT_Y))
		Y(cam->dir) = u_d_range(Y(cam->dir) - (move * 2), 360.0f, -360.0f);
	if (IS_BIT(g_isr_flags, ISR_DEC_ROT_Z))
		Z(cam->dir) = u_d_range(Z(cam->dir) - (move * 2), 360.0f, -360.0f);
}

static void	add_default_keys_event(float_t *const al, double_t const move)
{
	if (IS_BIT(g_isr_flags, ISR_INC_AL))
		*al = u_d_range(*al - move, 100, 1);
	if (IS_BIT(g_isr_flags, ISR_DEC_AL))
		*al = u_d_range(*al + move, 100, 1);
}

void				rt_sdl_keys_events(Environment *restrict const env)
{
	add_default_keys_event(&env->flags.ambient_light, env->fps.move);
	if (IS_BIT(g_isr_flags, ISR_LIGHT_DEBUG))
	{
		if (IS_BIT(g_isr_flags, ISR_OBJS_DEBUG))
			UNSET_BIT(g_isr_flags, ISR_LIGHT_DEBUG);
		else if (!IS_BIT(g_flags, F_BIT_NCL))
			rt_sdl_keys_events_lights_debug(env->scene.lights,
				&env->fps, env->scene.ins_lights);
	}
	else if (IS_BIT(g_isr_flags, ISR_OBJS_DEBUG))
		rt_sdl_keys_events_objs_debug(env->scene.objs,
			&env->fps, env->scene.ins_objs);
	else
		add_camera_events(&env->scene.cam, env->fps.move);
	rt_camera_speed_movements(&env->cam_speed);
}
