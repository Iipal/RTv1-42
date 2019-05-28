/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 19:54:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/28 19:25:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Color		rt_raytracing(Environment *restrict const env, Vector d)
{
	t_clhelp		h;
	Object			*obj;

	d = u_vnorm(rt_camera_rotate(d, env->scene.cam.dir));
	obj = rt_closest_inter(env->scene.cam.pos, d, env);
	NO_R(obj, U_CLR_BLACK);
	obj->dir = u_vnorm(obj->dir);
	h.p = u_vaddv(env->scene.cam.pos, u_vmuld(d, env->scene.cam.closes_t));
	h.n = obj->fn_normal_calc(h.p, d, &env->scene.cam, obj);
	h.n = u_vnorm(h.n);
	return (env->flags.no_calc_light
		? obj->clr : rt_calc_light(env, &h, obj, d));
}
