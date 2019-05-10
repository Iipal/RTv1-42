/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/10 11:29:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool		rt_intersection(Environment *env, t_vec d, fDot *t, int32_t i)
{
	const int16_t	r = env->s.objs[i].radius;
	const t_vec		ds = env->s.cam.pos - env->s.objs[i].pos;
	const t_vec		k = {VDOT(d, d), 2.0f * VDOT(ds, d), VDOT(ds, ds) - r * r};
	const double_t	disc = k[Y] * k[Y] - 4 * k[X] * k[Z];

	IF_F(.0f > disc);
	*t = (fDot){(-k[Y] + sqrt(disc)) / (2 * k[X]),
		(-k[Y] - sqrt(disc)) / (2 * k[X])};
	return (true);
}

inline Object	*rt_closest_inter(t_vec d, Environment *env,
					double_t t_min, double_t t_max)
{
	int32_t	i;
	fDot	t;

	i = -1;
	while (++i < env->s.ins_objs)
		if (rt_intersection(env, d, &t, i))
		{
			if (t.x >= t_min && t.x <= t_max && t.x < env->s.cobj)
				env->s.cobj = t.x;
			if (t.y >= t_min && t.y <= t_max && t.y < env->s.cobj)
				env->s.cobj = t.y;
			return (&env->s.objs[i]);
		}
	return (NULL);
}
