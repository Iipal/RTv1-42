/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 15:06:01 by tmaluh           ###   ########.fr       */
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
	const Vector	x = u_vsubv(o, obj->pos);
	const Vector	k = 1 != obj->type ? obj->fn_inter_calc(x, d, obj) : o;
	const double_t	disc = 1 != obj->type ? VDISC(k) : 0;

	if (obj->type == plane)
		return ((fDot){!u_vdot(d, obj->dir) ? -1
				: (-u_vdot(x, obj->dir) / u_vdot(d, obj->dir)), -1});
	else if (.0f > disc)
		return ((fDot){ -1, -1 });
	return ((fDot){ (-Y(k) + sqrt(disc)) / (2.0f * X(k)),
					(-Y(k) - sqrt(disc)) / (2.0f * X(k)) });
}

Object				*rt_closest_inter(const Vector o,
									const Vector d,
									Environment *const env)
{
	fDot			t;
	size_t			i;
	Object			*out_obj;

	i = ~0L;
	out_obj = NULL;
	env->s.cam.closes_t = env->t_max;
	while (++i < env->s.ins_objs)
	{
		t = add_intersection(o, d, &env->s.objs[i]);
		if (X(t) > env->t_min && X(t) < env->t_max
		&& X(t) < env->s.cam.closes_t)
		{
			env->s.cam.closes_t = X(t);
			out_obj = &env->s.objs[i];
		}
		if (Y(t) > env->t_min && Y(t) < env->t_max
		&& Y(t) < env->s.cam.closes_t)
		{
			env->s.cam.closes_t = Y(t);
			out_obj = &env->s.objs[i];
		}
	}
	return (out_obj);
}
