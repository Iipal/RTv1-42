/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 19:54:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/29 23:10:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline Color	add_uv_sphere(const Vector obj_pos,
								SDL_Surface *restrict const texture,
								const Vector p)
{
	const Uint32	*pxls = (const Uint32*)texture->pixels;
	const Vector	n = u_vnorm(p - obj_pos);
	Dot				uv;

	uv = (Dot){(0.5 + atan2(Z(n), X(n)) / (2.0 * M_PI)) * texture->w,
				(0.5 - asin(Y(n)) / M_PI) * texture->h};
	return ((Color){pxls[Y(uv) * texture->w + X(uv)]});
}

inline Color		rt_raytracing(Environment *restrict const env, Vector d)
{
	t_clhelp			h;
	Object *restrict	obj;

	d = u_vnorm(rt_camera_rotate(d, env->scene.cam.dir));
	obj = rt_closest_inter(env->scene.cam.pos, d, env);
	if (!obj)
		return (U_CLR_BLACK);
	else if (env->flags.no_calc_light)
		return (obj->clr);
	else
	{
		obj->dir = u_vnorm(obj->dir);
		h.p = u_vaddv(env->scene.cam.pos, u_vmuld(d, env->scene.cam.t));
		h.n = obj->fn_normal_calc(h.p, d, &env->scene.cam, obj);
		h.n = u_vnorm(h.n);
		h.curr_clr = obj->clr;
		h.obj_spec = obj->spec;
		if (env->flags.textured)
			h.curr_clr = add_uv_sphere(obj->pos, obj->texture, h.p);
	}
	return (rt_calc_light(env, &h, d));
}
