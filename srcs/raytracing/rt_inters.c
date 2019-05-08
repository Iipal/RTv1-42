/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_inters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/08 15:11:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_intersection(Environment *env, Vec d, fDot *t, int32_t i)
{
	const int16_t	r = env->s.objs[i].radius;
	const Vec		ds = u_sub_vec(env->s.cam.pos, env->s.objs[i].pos);
	const Vec		k = {VMUL(d, d), 2.0f * VMUL(ds, d), VMUL(ds, ds) - r * r};
	const double	disc = k.y * k.y - 4 * k.x * k.z;

	ISR(.0f > disc, false);
	t->x = (-k.y + sqrt(disc)) / (2 * k.x);
	t->y = (-k.y - sqrt(disc)) / (2 * k.x);
	return (true);
}
