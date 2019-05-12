/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/12 10:36:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline fDot	rt_intersection(const t_vec o,
									const t_vec d,
									const double_t d_dot_d,
									const Object obj)
{
	const float_t	r = (float_t)obj.radius;
	const t_vec		oc = o - obj.pos;
	const t_vec		k = {d_dot_d, 2.0f * VDOT(oc, d), VDOT(oc, oc) - r * r};
	const double_t	disc = Y(k) * Y(k) - 4.0f * X(k) * Z(k);

	if (.0f > disc)
		return ((fDot){-1, -1});
	return  ((fDot){(-Y(k) + sqrt(disc)) / (2.0f * X(k)),
					(-Y(k) - sqrt(disc)) / (2.0f * X(k))});
}

Object				*rt_closest_inter(const t_vec o, const t_vec d,
										Environment *env)
{
	fDot			t;
	size_t			i;
	Object			*obj;
	const double_t	d_dot_d = VDOT(d, d);

	i = ~0L;
	obj = NULL;
	while (++i < env->s.ins_objs)
	{
		t = rt_intersection(o, d, d_dot_d, env->s.objs[i]);
		if (t.x >= env->t_min && t.x < env->t_max && t.x < env->s.cobj)
		{
			env->s.cobj = t.x;
			obj = &env->s.objs[i];
		}
		if (t.y >= env->t_min && t.y < env->t_max && t.y < env->s.cobj)
		{
			env->s.cobj = t.y;
			obj = &env->s.objs[i];
		}
	}
	return (obj);
}
