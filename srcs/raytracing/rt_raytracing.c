/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 19:54:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/29 18:17:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline Color	add_texture_mapping_sphere(Object *restrict const obj,
								const Vector p)
{
	const Vector	n = u_vnorm(p - obj->pos);
	const Uint32	*pxls = obj->texture->pixels;
	Dot				uv;

	uv = (Dot){(0.5 + atan2(Z(n), X(n)) / (2.0 * M_PI)) * obj->texture->w,
				(0.5 - asin(Y(n)) / M_PI) * obj->texture->h};
	return ((Color){pxls[Y(uv) * obj->texture->w + X(uv)]});
}

inline Color		rt_raytracing(Environment *restrict const env, Vector d)
{
	t_clhelp			h;
	Object *restrict	obj;

	d = u_vnorm(rt_camera_rotate(d, env->scene.cam.dir));
	obj = rt_closest_inter(env->scene.cam.pos, d, env);
	NO_R(obj, U_CLR_BLACK);
	obj->dir = u_vnorm(obj->dir);
	h.p = u_vaddv(env->scene.cam.pos, u_vmuld(d, env->scene.cam.t));
	h.n = obj->fn_normal_calc(h.p, d, &env->scene.cam, obj);
	h.n = u_vnorm(h.n);
	h.curr_clr = obj->clr;
	h.obj_spec = obj->spec;
	if (env->flags.textured)
		h.curr_clr = add_texture_mapping_sphere(obj, h.p);
	return (env->flags.no_calc_light ? h.curr_clr : rt_calc_light(env, &h, d));
}
