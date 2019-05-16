/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_normals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:17:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/16 22:29:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Vector	rt_normal_sphere(const Vector p,
								const Camera *restrict cam,
								const void *restrict obj_ptr)
{
	(void)cam;
	return (p - ((Object*)obj_ptr)->pos);
}

inline Vector	rt_normal_cone(const Vector p,
								const Camera *restrict cam,
								const void *restrict obj_ptr)
{
	(void)cam;
	return (p - ((Object*)obj_ptr)->pos);
}

inline Vector	rt_normal_plane(const Vector p,
								const Camera *restrict cam,
								const void *restrict obj_ptr)
{
	(void)p;
	return (0 < VDOT(cam->pos, ((Object*)obj_ptr)->dir)
		? -((Object*)obj_ptr)->dir : ((Object*)obj_ptr)->dir);
}

inline Vector	rt_normal_cylinder(const Vector p,
								const Camera *restrict cam,
								const void *restrict obj_ptr)
{
	(void)cam;
	return (p - ((Object*)obj_ptr)->pos);
}
