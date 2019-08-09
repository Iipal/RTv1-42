/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_anti_aliasing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:31:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 08:55:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

Color	rt_anti_aliasing(Environment *restrict const env,
			size_t const aa, __v4df d_calc)
{
	double_t const	step = (1.0 / aa) / 1000.0;
	Color			outclr;
	__v4du			colors;
	__v2du			i;

	Y(i) = ~0UL;
	Y(d_calc) -= 0.001;
	colors = (__v4du){ 0UL } | 0UL;
	while (aa > ++Y(i) && (X(i) = ~0UL))
	{
		X(d_calc) -= 0.001;
		while (aa > ++X(i))
		{
			env->tmax = TMAX;
			env->tmin = TMIN;
			outclr = rt_raytracing(env, d_calc);
			colors = (__v4du) { X(colors) + outclr.c.r,
								Y(colors) + outclr.c.g,
								Z(colors) + outclr.c.b, 0UL };
			X(d_calc) += step;
		}
		Y(d_calc) += step;
	}
	return ((Color) {.c = { INRANGE(X(colors) / (aa * aa)),
							INRANGE(Y(colors) / (aa * aa)),
							INRANGE(Z(colors) / (aa * aa)) } } );
}
