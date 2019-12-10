/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_anti_aliasing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:31:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 22:26:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

Color	rt_anti_aliasing(void *restrict const arg, t_v4df d)
{
	Environment *restrict const	env = arg;
	const size_t				aa = env->flags.anti_aliasing;
	double_t const				step = (1.0 / aa) / 1000.0;
	Color						outclr;
	t_v4du						colors;
	__v2du						i;

	Y(i) = ~0UL;
	Y(d) -= 0.001;
	colors = (t_v4du){ 0UL };
	while (aa > ++Y(i) && (X(i) = ~0UL))
	{
		X(d) -= 0.001;
		while (aa > ++X(i))
		{
			env->scene.tmax = TMAX;
			env->scene.tmin = TMIN;
			outclr = rt_raytracing(env, d);
			colors = (t_v4du) { X(colors) + outclr.c.r,
								Y(colors) + outclr.c.g,
								Z(colors) + outclr.c.b, 0UL };
			X(d) += step;
		}
		Y(d) += step;
	}
	return ((Color) {.c = { INRANGE(X(colors) / (aa * aa)),
		INRANGE(Y(colors) / (aa * aa)), INRANGE(Z(colors) / (aa * aa)) } });
}
