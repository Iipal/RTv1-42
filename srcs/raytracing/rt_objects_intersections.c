/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:06:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/16 21:21:17 by tmaluh           ###   ########.fr       */
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
	const float_t	r = (float_t)(((Object*)obj_ptr)->radius);

	return ((Vector){VDOT(b, b), 2.0f * VDOT(a, b), VDOT(a, a) - r * r});
}

inline Vector	rt_inter_plane(const Vector a,
								const Vector b,
								const void *restrict obj_ptr)
{
	const float_t	r = (float_t)(((Object*)obj_ptr)->radius);

	return ((Vector){VDOT(b, b), 2.0f * VDOT(a, b), VDOT(a, a) - r * r});
}

inline Vector	rt_inter_cylinde(const Vector a,
								const Vector b,
								const void *restrict obj_ptr)
{
	const float_t	r = (float_t)(((Object*)obj_ptr)->radius);

	return ((Vector){VDOT(b, b), 2.0f * VDOT(a, b), VDOT(a, a) - r * r});
}
