/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:06:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/28 19:25:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Vector	rt_inter_sphere(const Vector x,
								const Vector d,
								const void *restrict const obj_ptr)
{
	const double_t	r = ((Object*)obj_ptr)->radius;

	return ((Vector){u_vdot(d, d), 2.0 * u_vdot(x, d),
					u_vdot(x, x) - r * r, 0.0});
}

inline Vector	rt_inter_cone(const Vector x,
								const Vector d,
								const void *restrict const obj_ptr)
{
	const Object	*obj = (Object*)obj_ptr;
	const double_t	k = 1 + pow(tan(obj->radius / 2.0f), 2);

	return ((Vector){u_vdot(d, d) - k * pow(u_vdot(d, obj->dir), 2),
	2.0f * (u_vdot(d, x) - k * u_vdot(d, obj->dir) * u_vdot(x, obj->dir)),
	u_vdot(x, x) - k * pow(u_vdot(x, obj->dir), 2), 0.0});
}

inline Vector	rt_inter_plane(const Vector x,
								const Vector d,
								const void *restrict const obj_ptr)
{
	(void)x;
	(void)d;
	(void)obj_ptr;
	return ((Vector){0.0, 0.0, 0.0, 0.0});
}

inline Vector	rt_inter_cylinder(const Vector x,
								const Vector d,
								const void *restrict const obj_ptr)
{
	const Vector	obj_dir = u_vnorm(((Object*)obj_ptr)->dir);
	const double_t	r = ((Object*)obj_ptr)->radius;

	return ((Vector){u_vdot(d, d) - pow(u_vdot(d, obj_dir), 2.0f),
		2.0f * (u_vdot(x, d) - u_vdot(x, obj_dir) * u_vdot(d, obj_dir)),
		u_vdot(x, x) - pow(u_vdot(x, obj_dir), 2.0f) - r * r, 0.0});
}
