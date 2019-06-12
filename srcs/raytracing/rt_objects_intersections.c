/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:06:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/12 17:21:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline __v4df	rt_inter_sphere(const __v4df x,
								const __v4df d,
								const void *restrict const obj_ptr)
{
	const double_t	r = ((Object*)obj_ptr)->radius;

	return ((__v4df){v_dot(d, d), 2.0 * v_dot(x, d),
					v_dot(x, x) - r * r, 0.0});
}

inline __v4df	rt_inter_cone(const __v4df x,
								const __v4df d,
								const void *restrict const obj_ptr)
{
	const Object	*obj = (Object*)obj_ptr;
	const double_t	k = 1 + pow(tan(obj->radius / 2.0f), 2);

	return ((__v4df){v_dot(d, d) - k * pow(v_dot(d, obj->dir), 2),
		2.0f * (v_dot(d, x) - k * v_dot(d, obj->dir) * v_dot(x, obj->dir)),
		v_dot(x, x) - k * pow(v_dot(x, obj->dir), 2), 0.0});
}

inline __v4df	rt_inter_plane(const __v4df x,
								const __v4df d,
								const void *restrict const obj_ptr)
{
	(void)x;
	(void)d;
	(void)obj_ptr;
	return ((__v4df){0.0, 0.0, 0.0, 0.0});
}

inline __v4df	rt_inter_cylinder(const __v4df x,
								const __v4df d,
								const void *restrict const obj_ptr)
{
	const __v4df	obj_dir = v_norm(((Object*)obj_ptr)->dir);
	const double_t	r = ((Object*)obj_ptr)->radius;

	return ((__v4df){v_dot(d, d) - pow(v_dot(d, obj_dir), 2.0f),
		2.0f * (v_dot(x, d) - v_dot(x, obj_dir) * v_dot(d, obj_dir)),
		v_dot(x, x) - pow(v_dot(x, obj_dir), 2.0f) - r * r, 0.0});
}
