/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 20:02:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline fDot	rt_intersection(const Vector o,
									const Vector d,
									const double_t d_dot_d,
									const Object obj)
{
	const float_t	r = (float_t)obj.radius;
	const Vector	oc = o - obj.pos;
	const Vector	k = {d_dot_d, 2.0f * VDOT(oc, d), VDOT(oc, oc) - r * r};
	const double_t	disc = Y(k) * Y(k) - 4.0f * X(k) * Z(k);

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
	const double_t	d_dot_d = VDOT(d, d);

	i = ~0L;
	out_obj = NULL;
	env->s.cobj = env->t_max;
	while (++i < env->s.ins_objs)
	{
		t = rt_intersection(o, d, d_dot_d, env->s.objs[i]);
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
