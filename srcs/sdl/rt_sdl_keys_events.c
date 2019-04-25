/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_keys_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:12:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/25 19:58:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_sdl_keys_events(Environment *env)
{
	if (env->isr.is_cam_up)
		env->s.cam.pos.y = u_inrangev(env->s.cam.pos.y - env->fps.move, 1, 0);
	if (env->isr.is_cam_down)
		env->s.cam.pos.y = u_inrangev(env->s.cam.pos.y + env->fps.move, 0, 1);
	if (env->isr.is_cam_left)
		env->s.cam.pos.x = u_inrangev(env->s.cam.pos.x - env->fps.move, 1, 0);
	if (env->isr.is_cam_right)
		env->s.cam.pos.x = u_inrangev(env->s.cam.pos.x + env->fps.move, 0, 1);
	if (env->isr.is_cam_zdec)
		env->s.cam.pos.z = u_inrangev(env->s.cam.pos.z - env->fps.move, 1, 0);
	if (env->isr.is_cam_zinc)
		env->s.cam.pos.z = u_inrangev(env->s.cam.pos.z + env->fps.move, 0, 1);
}
