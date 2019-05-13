/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/13 15:11:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline fDot	rt_intersection(const t_v o,
									const t_v d,
									const double_t d_dot_d,
									const Object obj)
{
	const float_t	r = (float_t)obj.radius;
	const t_v		oc = o - obj.pos;
	const t_v		k = {d_dot_d, 2.0f * VDOT(oc, d), VDOT(oc, oc) - r * r};
	const double_t	disc = Y(k) * Y(k) - 4.0f * X(k) * Z(k);

	if (.0f > disc)
		return ((fDot){-1, -1});
	return  ((fDot){(-Y(k) + sqrt(disc)) / (2.0f * X(k)),
					(-Y(k) - sqrt(disc)) / (2.0f * X(k))});
}

Object				*rt_closest_inter(const t_v o,
									const t_v d,
									Environment *env,
									bool is_shadow)
{
	fDot			t;
	size_t			i;
	Object			*out_obj;
	const double_t	d_dot_d = VDOT(d, d);

	i = ~0L;
	out_obj = NULL;
	IFDO(!is_shadow, env->t_min = TMIN);
	IFDO(!is_shadow, env->t_max = TMAX);
	while (++i < env->s.ins_objs)
	{
		t = rt_intersection(o, d, d_dot_d, env->s.objs[i]);
		if (t.x >= env->t_min && t.x < env->t_max && t.x < env->s.cobj)
		{
			!is_shadow ? (env->s.cobj = t.x) : 0;
			out_obj = &env->s.objs[i];
		}
		if (t.y >= env->t_min && t.y < env->t_max && t.y < env->s.cobj)
		{
			!is_shadow ? (env->s.cobj = t.y) : 0;
			out_obj = &env->s.objs[i];
		}
	}
	return (out_obj);
}
