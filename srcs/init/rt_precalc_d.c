/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_precalc_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:24:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/12 19:27:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_precalc_d(Environment *restrict const env)
{
	__v2df	p;
	__v2si	tp;

	X(tp) = -1;
	MEM(__v4df*, env->pre_calc_d, WIN_Y, E_ALLOC);
	while (WIN_Y > ++X(tp))
		MEM(__v4df, env->pre_calc_d[X(tp)], WIN_X, E_ALLOC);
	Y(p) = RT_CANVAS_STARTY;
	Y(tp) = -1;
	while (RT_CANVAS_ENDY > ++Y(p) && (X(p) = RT_CANVAS_STARTX))
	{
		++Y(tp);
		X(tp) = -1;
		while (RT_CANVAS_ENDX > ++X(p))
		{
			++X(tp);
			env->pre_calc_d[Y(tp)][X(tp)] = (__v4df){
					X(p) * WIN_X / (1000.0f * WIN_X),
					Y(p) * WIN_Y / (1000.0f * WIN_Y),
						env->flags.viewport_scale};
		}
	}
	return (true);
}
