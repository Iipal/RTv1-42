/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/16 23:52:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline fDot	rt_intersection(const Vector o,
									const Vector d,
									const Object *obj)
{
	const Vector	oc = o - obj->pos;
	const Vector	k = obj->fn_inter_calc(oc, d, obj);
	const double_t	disc = Y(k) * Y(k) - 4.0f * X(k) * Z(k);

	if (obj->type == plane)
		return ((fDot){!VDOT(d, obj->dir) ? -1
					: -VDOT(oc, obj->dir) / VDOT(d, obj->dir), -1});
	if (.0f > disc)
		return ((fDot){-1, -1});
	return ((fDot){ (-Y(k) + sqrt(disc)) / (2.0f * X(k)),
					(-Y(k) - sqrt(disc)) / (2.0f * X(k)) });
}

Object				*rt_closest_inter(const Vector o,
									const Vector d,
									Environment *env)
{
	fDot			t;
	size_t			i;
	Object			*out_obj;

	i = ~0L;
	out_obj = NULL;
	env->s.cobj = env->t_max;
	while (++i < env->s.ins_objs)
	{
		t = rt_intersection(o, d, &env->s.objs[i]);
		if (t.x >= env->t_min && t.x < env->t_max && t.x < env->s.cobj)
		{
			env->s.cobj = t.x;
			out_obj = &env->s.objs[i];
		}
		if (t.y >= env->t_min && t.y < env->t_max && t.y < env->s.cobj)
		{
			env->s.cobj = t.y;
			out_obj = &env->s.objs[i];
		}
	}
	return (out_obj);
}
