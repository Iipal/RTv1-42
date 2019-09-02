/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_precalc_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:24:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/09/02 21:51:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_precalc_d(Environment *restrict const env)
{
	t_v2df	p;
	__v2si	tp;

	X(tp) = -1;
	MEM(t_v4df*, env->pre_calc_d, WIN_Y, E_ALLOC);
	while (WIN_Y > ++X(tp))
		MEM(t_v4df, env->pre_calc_d[X(tp)], WIN_X, E_ALLOC);
	Y(p) = RT_CANVAS_STARTY;
	Y(tp) = -1;
	while (RT_CANVAS_ENDY > ++Y(p) && (X(p) = RT_CANVAS_STARTX))
	{
		++Y(tp);
		X(tp) = -1;
		while (RT_CANVAS_ENDX > ++X(p))
		{
			++X(tp);
			env->pre_calc_d[Y(tp)][X(tp)] = (t_v4df){
						X(p) * WIN_X / (1000.0 * WIN_X),
						Y(p) * WIN_Y / (1000.0 * WIN_Y),
						env->flags.viewport_scale, 0.0};
		}
	}
	return (true);
}
