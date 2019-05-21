/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:06:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/21 22:38:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Vector	rt_inter_sphere(const Vector x,
								const Vector d,
								const void *const obj_ptr)
{
	const double_t	r = ((Object*)obj_ptr)->radius;

	return ((Vector){VDOT(d, d), 2.0f * VDOT(x, d), VDOT(x, x) - r * r});
}

inline Vector	rt_inter_cone(const Vector x,
								const Vector d,
								const void *const obj_ptr)
{
	const Object	*obj = (Object*)obj_ptr;
	const double_t	k = 1 + pow(tan(obj->radius / 2.0f), 2);

	return ((Vector){VDOT(d, d) - k * pow(VDOT(d, obj->dir), 2),
		2.0f * (VDOT(d, x) - k * (VDOT(d, obj->dir) * VDOT(x, obj->dir))),
		VDOT(x, x) - k * (pow(VDOT(x, obj->dir), 2))});
}

inline Vector	rt_inter_plane(const Vector x,
								const Vector d,
								const void *const obj_ptr)
{
	(void)x;
	(void)d;
	(void)obj_ptr;
	return ((Vector){-1, -1});
}

inline Vector	rt_inter_cylinder(const Vector x,
								const Vector d,
								const void *const obj_ptr)
{
	const Vector	obj_dir = u_vec_norm(((Object*)obj_ptr)->dir);
	const double_t	r = ((Object*)obj_ptr)->radius;

	return ((Vector){VDOT(d, d) - pow(VDOT(d, obj_dir), 2.0f),
		2.0f * (VDOT(x, d) - VDOT(x, obj_dir) * VDOT(d, obj_dir)),
		VDOT(x, x) - pow(VDOT(x, obj_dir), 2.0f) - r * r});
}
