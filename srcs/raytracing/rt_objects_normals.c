/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_normals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:17:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 08:52:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

__v4df	rt_normal_sphere(__v4df const p, __v4df const d,
			Camera const *restrict const cam,
			void const *restrict const obj_ptr)
{
	(void)d;
	(void)cam;
	return (p - ((Object const *restrict const)obj_ptr)->pos);
}

__v4df	rt_normal_cone(__v4df const p, __v4df const d,
			Camera const *restrict const cam,
			void const *restrict const obj_ptr)
{
	Object const *restrict const	o = (Object const *restrict const)obj_ptr;

	return (p - o->pos -
		v_mul_d(v_mul_d(o->dir, 1.0 + pow(tan(o->radius / 2.0), 2.0)),
			v_dot(d, o->dir) * cam->t + v_dot(cam->pos - o->pos, o->dir)));
}

__v4df	rt_normal_plane(__v4df const p, __v4df const d,
			Camera const *restrict const cam,
			void const *restrict const obj_ptr)
{
	__v4df const	obj_dir = ((Object const *restrict const)obj_ptr)->dir;

	(void)p;
	(void)cam;
	return (0.0 < v_dot(d, obj_dir) ? -obj_dir : obj_dir);
}

__v4df	rt_normal_cylinder(__v4df const p, __v4df const d,
			Camera const *restrict const cam,
			void const *restrict const obj_ptr)
{
	__v4df const	o_pos = ((Object const *restrict const)obj_ptr)->pos;
	__v4df const	o_dir = ((Object const *restrict const)obj_ptr)->dir;

	return (p - o_pos - v_mul_d(o_dir,
		v_dot(d, o_dir) * cam->t + v_dot(cam->pos - o_pos, o_dir)));
}
