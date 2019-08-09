/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:06:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 08:50:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

__v4df	rt_inter_sphere(__v4df const x, __v4df const d,
			void const *restrict const obj_ptr)
{
	double_t const	r = ((Object*)obj_ptr)->radius;

	return ((__v4df){v_dot(d, d), 2.0 * v_dot(x, d),
						v_dot(x, x) - r * r, 0.0});
}

__v4df	rt_inter_cone(__v4df const x, __v4df const d,
			void const *restrict const obj_ptr)
{
	Object const	*obj = (Object*)obj_ptr;
	double_t const	k = 1 + pow(tan(obj->radius / 2.0), 2.0);

	return ((__v4df){v_dot(d, d) - k * pow(v_dot(d, obj->dir), 2.0),
		2.0 * (v_dot(d, x) - k * v_dot(d, obj->dir) * v_dot(x, obj->dir)),
		v_dot(x, x) - k * pow(v_dot(x, obj->dir), 2.0), 0.0});
}

__v4df	rt_inter_plane(__v4df const x, __v4df const d,
			void const *restrict const obj_ptr)
{
	(void)x;
	(void)d;
	(void)obj_ptr;
	return ((__v4df){0.0, 0.0, 0.0, 0.0});
}

__v4df	rt_inter_cylinder(__v4df const x, __v4df const d,
			void const *restrict const obj_ptr)
{
	__v4df const	obj_dir = v_norm(((Object*)obj_ptr)->dir);
	double_t const	r = ((Object*)obj_ptr)->radius;

	return ((__v4df){v_dot(d, d) - pow(v_dot(d, obj_dir), 2.0f),
		2.0f * (v_dot(x, d) - v_dot(x, obj_dir) * v_dot(d, obj_dir)),
		v_dot(x, x) - pow(v_dot(x, obj_dir), 2.0f) - r * r, 0.0});
}
