/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/10 19:35:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	rt_intersection(const t_vec o, const t_vec d,
	const double_t d_dot_d, const Object obj, fDot *t)
{
	const int16_t	r = obj.radius;
	const t_vec		oc = o - obj.pos;
	const t_vec		k = {d_dot_d, 2.0f * VDOT(oc, d), VDOT(oc, oc) - r * r};
	const double_t	disc = k[Y] * k[Y] - 4.0f * k[X] * k[Z];

	if (.0f > disc)
		*t = (fDot) {-1, -1};
	else
		*t = (fDot){(-k[Y] + sqrt(disc)) / (2.0f * k[X]),
					(-k[Y] - sqrt(disc)) / (2.0f * k[X])};
}

Object				*rt_closest_inter(t_vec o, t_vec d, Environment *env)
{
	int32_t			i;
	fDot			t;
	Object			*obj;
	const double_t	d_dot_d = VDOT(d, d);

	i = -1;
	obj = NULL;
	while (++i < env->s.ins_objs)
	{
		rt_intersection(o, d, d_dot_d, env->s.objs[i], &t);
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
