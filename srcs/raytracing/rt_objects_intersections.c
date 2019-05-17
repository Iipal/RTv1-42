/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:06:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 17:32:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Vector	rt_inter_sphere(const Vector a,
								const Vector b,
								const void *restrict obj_ptr)
{
	const float_t	r = (float_t)(((Object*)obj_ptr)->radius);

	return ((Vector){VDOT(b, b), 2.0f * VDOT(a, b), VDOT(a, a) - r * r});
}

inline Vector	rt_inter_cone(const Vector a,
								const Vector b,
								const void *restrict obj_ptr)
{
	const Object	*obj = (Object*)obj_ptr;
	const float_t	r = (float_t)(obj->radius);

	return ((Vector){
		VDOT(b, b) - (pow(VDOT(b, obj->dir), 2) * (1 + pow(r / 2.0f, 2))),
		2.0f * (VDOT(b, a) - ((1.0f * pow(tan(r / 2.0f), 2))
			* VDOT(b, obj->dir) * VDOT(a, obj->dir))),
	VDOT(a, a) - (pow(VDOT(a, obj->dir), 2) * (1 + pow(tan(r / 2.0f), 2))) });
}

inline Vector	rt_inter_plane(const Vector a,
								const Vector b,
								const void *restrict obj_ptr)
{
	(void)a;
	(void)b;
	(void)obj_ptr;
	return ((Vector){0, 0});
}

inline Vector	rt_inter_cylinder(const Vector a,
								const Vector b,
								const void *restrict obj_ptr)
{
	const float_t	r = (float_t)(((Object*)obj_ptr)->radius);

	return ((Vector){VDOT(b, b), 2.0f * VDOT(a, b), VDOT(a, a) - r * r});
}
