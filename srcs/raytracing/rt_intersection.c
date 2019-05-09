/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/09 11:46:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_intersection(Environment *env, t_vec d, fDot *t, int32_t i)
{
	const int16_t	r = env->s.objs[i].radius;
	const t_vec		ds = env->s.cam.pos - env->s.objs[i].pos;
	const t_vec		k = {VDOT(d, d), 2.0f * VDOT(ds, d), VDOT(ds, ds) - r * r};
	const double_t	disc = k[Y] * k[Y] - 4 * k[X] * k[Z];

	ISR(.0f > disc, false);
	*t = (fDot){ (-k[Y] + sqrt(disc)) / (2 * k[X]),
		(-k[Y] - sqrt(disc)) / (2 * k[X]) };
	return (true);
}
