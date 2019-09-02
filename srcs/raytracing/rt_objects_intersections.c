/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:06:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/09/02 21:51:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_v4df	rt_inter_sphere(t_v4df const x, t_v4df const d,
			void const *restrict const obj_ptr)
{
	double_t const	r = ((Object*)obj_ptr)->radius;

	return ((t_v4df){v_dot(d, d), 2.0 * v_dot(x, d),
						v_dot(x, x) - r * r, 0.0});
}

t_v4df	rt_inter_cone(t_v4df const x, t_v4df const d,
			void const *restrict const obj_ptr)
{
	Object const	*obj = (Object*)obj_ptr;
	double_t const	k = 1 + pow(tan(obj->radius / 2.0), 2.0);

	return ((t_v4df){v_dot(d, d) - k * pow(v_dot(d, obj->dir), 2.0),
		2.0 * (v_dot(d, x) - k * v_dot(d, obj->dir) * v_dot(x, obj->dir)),
		v_dot(x, x) - k * pow(v_dot(x, obj->dir), 2.0), 0.0});
}

t_v4df	rt_inter_cylinder(t_v4df const x, t_v4df const d,
			void const *restrict const obj_ptr)
{
	t_v4df const	obj_dir = v_norm(((Object*)obj_ptr)->dir);
	double_t const	r = ((Object*)obj_ptr)->radius;

	return ((t_v4df){v_dot(d, d) - pow(v_dot(d, obj_dir), 2.0f),
		2.0f * (v_dot(x, d) - v_dot(x, obj_dir) * v_dot(d, obj_dir)),
		v_dot(x, x) - pow(v_dot(x, obj_dir), 2.0f) - r * r, 0.0});
}
