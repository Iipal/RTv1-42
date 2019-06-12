/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_normals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:17:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/12 17:23:40 by tmaluh           ###   ########.fr       */
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
	return (p - ((Object*)obj_ptr)->pos);
}

inline __v4df	rt_normal_cone(const __v4df p,
								const __v4df d,
								const Camera *restrict const cam,
								const void *restrict const obj_ptr)
{
	const Object *restrict	o = (Object*)obj_ptr;

	return (p - o->pos -
		v_mul_d(v_mul_d(o->dir, 1 + pow(tan(o->radius / 2), 2)),
			v_dot(d, o->dir) * cam->t + v_dot(cam->pos - o->pos, o->dir)));
}

inline __v4df	rt_normal_plane(const __v4df p,
								const __v4df d,
								const Camera *restrict const cam,
								const void *restrict const obj_ptr)
{
	const __v4df	obj_dir = ((Object*)obj_ptr)->dir;

	(void)p;
	(void)cam;
	return (0 < v_dot(d, obj_dir) ? -obj_dir : obj_dir);
}

inline __v4df	rt_normal_cylinder(const __v4df p,
								const __v4df d,
								const Camera *restrict const cam,
								const void *restrict const obj_ptr)
{
	const __v4df	o_pos = ((Object*)obj_ptr)->pos;
	const __v4df	o_dir = ((Object*)obj_ptr)->dir;

	return (p - o_pos - v_mul_d(o_dir,
		v_dot(d, o_dir) * cam->t + v_dot(cam->pos - o_pos, o_dir)));
}
