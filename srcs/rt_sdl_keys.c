/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:07:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/19 17:34:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_sdl_keys_press(Environment *env)
{
	if (SDLK_w == SEKEY)
		env->isr.is_cam_up = true;
	else if (SDLK_s == SEKEY)
		env->isr.is_cam_down = true;
	else if (SDLK_a == SEKEY)
		env->isr.is_cam_left = true;
	else if (SDLK_d == SEKEY)
		env->isr.is_cam_right = true;
	else if (SDLK_q == SEKEY)
		env->isr.is_cam_zdec = true;
	else if (SDLK_e == SEKEY)
		env->isr.is_cam_zinc = true;
}

inline void	rt_sdl_keys_release(Environment *env)
{
	if (SDLK_w == SEKEY)
		env->isr.is_cam_up = false;
	else if (SDLK_s == SEKEY)
		env->isr.is_cam_down = false;
	else if (SDLK_a == SEKEY)
		env->isr.is_cam_left = false;
	else if (SDLK_d == SEKEY)
		env->isr.is_cam_right = false;
	else if (SDLK_q == SEKEY)
		env->isr.is_cam_zdec = false;
	else if (SDLK_e == SEKEY)
		env->isr.is_cam_zinc = false;
}

inline void	rt_sdl_keys_events(Environment *env)
{
	IFDO(env->isr.is_cam_up, env->s.cam.pos.y -= CAM_M);
	IFDO(env->isr.is_cam_down, env->s.cam.pos.y += CAM_M);
	IFDO(env->isr.is_cam_left, env->s.cam.pos.x -= CAM_M);
	IFDO(env->isr.is_cam_right, env->s.cam.pos.x += CAM_M);
	IFDO(env->isr.is_cam_zdec, env->s.cam.pos.z -= CAM_M);
	IFDO(env->isr.is_cam_zinc, env->s.cam.pos.z += CAM_M);
}
