/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:06:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/20 17:53:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Vector	rt_inter_sphere(const Vector a,
								const Vector b,
								const void *const obj_ptr)
{
	const double_t	r = ((Object*)obj_ptr)->radius;

	return ((Vector){VDOT(b, b), 2.0f * VDOT(a, b), VDOT(a, a) - r * r});
}

inline Vector	rt_inter_cone(const Vector a,
								const Vector b,
								const void *const obj_ptr)
{
	const Object	*obj = (Object*)obj_ptr;
	const double_t	k = 1 + pow(tan(obj->radius / 2.0f), 2);

	return ((Vector){VDOT(b, b) - k * pow(VDOT(b, obj->dir), 2),
		2.0f * (VDOT(b, a) - k * (VDOT(b, obj->dir) * VDOT(a, obj->dir))),
		VDOT(a, a) - k * (pow(VDOT(a, obj->dir), 2))});
}

inline Vector	rt_inter_plane(const Vector a,
								const Vector b,
								const void *const obj_ptr)
{
	(void)a;
	(void)b;
	(void)obj_ptr;
	return ((Vector){0, 0});
}

inline Vector	rt_inter_cylinder(const Vector a,
								const Vector b,
								const void *const obj_ptr)
{
	const Object	*obj = (Object*)obj_ptr;
	const double_t	r = obj->radius;

	return ((Vector){VDOT(b, b) - pow(VDOT(b, obj->dir), 2),
		2.0f * (VDOT(b, a) - (VDOT(b, obj->dir) * VDOT(a, obj->dir))),
		VDOT(a, a) - (pow(VDOT(a, obj->dir), 2)) - r * r});
}
