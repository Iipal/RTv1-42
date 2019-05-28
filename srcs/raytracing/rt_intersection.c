/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/28 12:45:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	1 == obj->type if it's plane. For plane don't neccessary calc discriminant.
*/

static inline fDot	add_intersection(const Vector o,
									const Vector d,
									const Object *const obj)
{
	const Vector	x = o - obj->pos;
	const Vector	k = obj->fn_inter_calc(x, d, obj);
	const double_t	disc = VDISC(k);

	if (.0f > disc)
		return ((fDot){ -1, -1 });
	return ((fDot){ (-Y(k) + sqrt(disc)) / (2.0f * X(k)),
					(-Y(k) - sqrt(disc)) / (2.0f * X(k)) });
}

static inline fDot	add_plane_calc(const Vector d, const Vector o,
						const Object *restrict const obj)
{
	return ((fDot){!u_vdot(d, obj->dir) ? -1
			: (-u_vdot(o - obj->pos, obj->dir) / u_vdot(d, obj->dir)), -1});
}

Object				*rt_closest_inter(const Vector o,
									const Vector d,
									Environment *const env)
{
	fDot				t;
	size_t				i;
	Object *restrict	out_obj;
	Object *restrict	curr_obj;

	i = ~0L;
	out_obj = NULL;
	env->s.cam.closes_t = env->tmax;
	while (++i < env->s.ins_objs)
	{
		curr_obj = &env->s.objs[i];
		if (plane == curr_obj->type)
			t = add_plane_calc(d, o, curr_obj);
		else
			t = add_intersection(o, d, curr_obj);
		if (X(t) > env->tmin && X(t) < env->tmax && X(t) < env->s.cam.closes_t)
		{
			env->s.cam.closes_t = X(t);
			out_obj = curr_obj;
		}
		if (Y(t) > env->tmin && Y(t) < env->tmax && Y(t) < env->s.cam.closes_t)
		{
			env->s.cam.closes_t = Y(t);
			out_obj = curr_obj;
		}
	}
	return (out_obj);
}
