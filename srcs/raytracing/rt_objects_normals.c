/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_normals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:17:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/22 13:38:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Vector	rt_normal_sphere(const Vector p,
								const Vector d,
								const Camera *const cam,
								const void *const obj_ptr)
{
	(void)d;
	(void)cam;
	return (p - ((Object*)obj_ptr)->pos);
}

inline Vector	rt_normal_cone(const Vector p,
								const Vector d,
								const Camera *const cam,
								const void *const obj_ptr)
{
	const Object	*o = (Object*)obj_ptr;

	return (p - o->pos - u_vmul(u_vmul(o->dir, 1 + pow(tan(o->radius / 2), 2)),
		u_vdot(d, o->dir) * cam->closes_t + u_vdot(cam->pos - o->pos, o->dir)));
}

inline Vector	rt_normal_plane(const Vector p,
								const Vector d,
								const Camera *const cam,
								const void *const obj_ptr)
{
	const Vector	obj_dir = ((Object*)obj_ptr)->dir;

	(void)p;
	(void)cam;
	return (0 < u_vdot(d, obj_dir) ? -obj_dir : p);
}

inline Vector	rt_normal_cylinder(const Vector p,
								const Vector d,
								const Camera *const cam,
								const void *const obj_ptr)
{
	const Vector	o_pos = ((Object*)obj_ptr)->pos;
	const Vector	o_dir = ((Object*)obj_ptr)->dir;

	return (p - o_pos - u_vmul(o_dir,
		u_vdot(d, o_dir) * cam->closes_t + u_vdot(cam->pos - o_pos, o_dir)));
}
