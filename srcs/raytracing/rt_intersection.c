/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/29 17:57:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	1 == obj->type if it's plane. For plane don't neccessary calc discriminant.
*/

static inline fDot	add_intersection(const Vector o,
									const Vector d,
									const Object *restrict const obj)
{
	const Vector	x = o - obj->pos;
	const Vector	k = obj->fn_inter_calc(x, d, obj);
	const double_t	disc = VDISC(k);

	if (.0f > disc)
		return ((fDot){ -1, -1 });
	return ((fDot){ (-Y(k) + sqrt(disc)) / (2.0f * X(k)),
					(-Y(k) - sqrt(disc)) / (2.0f * X(k)) });
}

static inline fDot	add_plane_inter(const Vector d, const Vector o,
						const Object *restrict const obj)
{
	return ((fDot){!u_vdot(d, obj->dir) ? -1
			: (-u_vdot(o - obj->pos, obj->dir) / u_vdot(d, obj->dir)), -1});
}

Object				*rt_closest_inter(const Vector o,
									const Vector d,
									Environment *restrict const env)
{
	fDot				t;
	size_t				i;
	Object *restrict	out_obj;

	i = ~0L;
	out_obj = NULL;
	env->scene.cam.t = env->tmax;
	while (++i < env->scene.ins_objs)
	{
		(plane == env->scene.objs[i].type)
			? (t = add_plane_inter(d, o, &env->scene.objs[i]))
			: (t = add_intersection(o, d, &env->scene.objs[i]));
		if (X(t) > env->tmin && X(t) < env->tmax && X(t) < env->scene.cam.t)
		{
			env->scene.cam.t = X(t);
			out_obj = &env->scene.objs[i];
		}
		if (Y(t) > env->tmin && Y(t) < env->tmax && Y(t) < env->scene.cam.t)
		{
			env->scene.cam.t = Y(t);
			out_obj = &env->scene.objs[i];
		}
	}
	return (out_obj);
}
