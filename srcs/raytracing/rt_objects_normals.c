/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_normals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:17:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 22:35:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Vector	rt_normal_sphere(const Vector p,
								const Vector d,
								const Camera *restrict cam,
								const void *restrict obj_ptr)
{
	(void)cam;
	(void)d;
	return (p - ((Object*)obj_ptr)->pos);
}

inline Vector	rt_normal_cone(const Vector p,
								const Vector d,
								const Camera *restrict cam,
								const void *restrict obj_ptr)
{
	const Object	*obj = (Object*)obj_ptr;
	const double_t	c = (VDOT(d, ((Object*)obj_ptr)->dir) * TMAX)
		+ VDOT((cam->pos - ((Object*)obj_ptr)->pos), ((Object*)obj_ptr)->dir);

	(void)cam;
	(void)d;
	return (p - obj->pos - VMUL(obj->dir,
		(c * (1 + pow(tan(obj->radius / 2.0f), 2)))));
}

inline Vector	rt_normal_plane(const Vector p,
								const Vector d,
								const Camera *restrict cam,
								const void *restrict obj_ptr)
{
	const Vector	obj_dir = ((Object*)obj_ptr)->dir;

	(void)p;
	(void)cam;
	return (0 < VDOT(d, obj_dir) ? -obj_dir : obj_dir);
}

inline Vector	rt_normal_cylinder(const Vector p,
								const Vector d,
								const Camera *restrict cam,
								const void *restrict obj_ptr)
{
	const Vector	obj_dir = ((Object*)obj_ptr)->dir;
	const double_t	m = (VDOT(d, obj_dir) * TMAX) + VDOT(p, obj_dir);

	(void)cam;
	return (p - ((Object*)obj_ptr)->pos - VMUL(obj_dir, m));
}
