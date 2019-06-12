/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 19:54:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/12 17:23:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Color		rt_raytracing(Environment *restrict const env, __v4df d)
{
	t_clhelp			h;
	Object *restrict	obj;

	d = v_norm(rt_camera_rotate(d, env->scene.cam.dir));
	obj = rt_closest_inter(env->scene.cam.pos, d, env);
	if (!obj)
		return (U_CLR_BLACK);
	else if (env->flags.no_calc_light && !env->flags.textured)
		return (obj->clr);
	else
	{
		h.curr_clr = obj->clr;
		h.p = env->scene.cam.pos + v_mul_d(d, env->scene.cam.t);
		if (env->flags.textured)
			h.curr_clr.hex = obj->fn_uv(obj->texture, v_norm(h.p - obj->pos));
		if (env->flags.no_calc_light)
			return (h.curr_clr);
		h.obj_spec = obj->spec;
		h.n = v_norm(obj->fn_normal_calc(h.p, d, &env->scene.cam, obj));
	}
	return (rt_calc_light(env, &h, -d));
}
