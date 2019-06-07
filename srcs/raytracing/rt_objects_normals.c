/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_normals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:17:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/07 19:17:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline __v4df	rt_normal_sphere(const __v4df p,
								const __v4df d,
								const Camera *restrict const cam,
								const void *restrict const obj_ptr)
{
	(void)d;
	(void)cam;
	return (u_vsubv(p, ((Object*)obj_ptr)->pos));
}

inline __v4df	rt_normal_cone(const __v4df p,
								const __v4df d,
								const Camera *restrict const cam,
								const void *restrict const obj_ptr)
{
	const Object *restrict	o = (Object*)obj_ptr;

	return (u_vsubv(u_vsubv(p, o->pos),
		u_vmuld(u_vmuld(o->dir, 1 + pow(tan(o->radius / 2), 2)),
			u_vdot(d, o->dir) * cam->t
				+ u_vdot(u_vsubv(cam->pos, o->pos), o->dir))));
}

inline __v4df	rt_normal_plane(const __v4df p,
								const __v4df d,
								const Camera *restrict const cam,
								const void *restrict const obj_ptr)
{
	const __v4df	obj_dir = ((Object*)obj_ptr)->dir;

	(void)p;
	(void)cam;
	return (0 < u_vdot(d, obj_dir) ? u_vinvert(obj_dir) : obj_dir);
}

inline __v4df	rt_normal_cylinder(const __v4df p,
								const __v4df d,
								const Camera *restrict const cam,
								const void *restrict const obj_ptr)
{
	const __v4df	o_pos = ((Object*)obj_ptr)->pos;
	const __v4df	o_dir = ((Object*)obj_ptr)->dir;

	return (u_vsubv(u_vsubv(p, o_pos), u_vmuld(o_dir,
u_vdot(d, o_dir) * cam->t + u_vdot(u_vsubv(cam->pos, o_pos), o_dir))));
}
