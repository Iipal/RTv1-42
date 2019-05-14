/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:23:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 12:32:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_raytracing(Environment *env)
{
	Dot		i;
	t_v		d;
	Object	*curr_obj;
	Color	curr_color;

	curr_obj = NULL;
	i.y = RT_CANVAS_STARTY;
	while (RT_CANVAS_ENDY > ++(i.y) && (i.x = RT_CANVAS_STARTX))
		while (RT_CANVAS_ENDX > ++(i.x))
		{
			env->s.cobj = TMAX;
			curr_color = CLR_BLACK;
			d = (t_v) {i.x * WIN_X / (1000.0f * WIN_X),
				i.y * WIN_Y / (1000.0f * WIN_Y), env->flags.viewport_scale};
			curr_obj = rt_closest_inter(env->s.cam.pos, d, env, false);
			if (curr_obj)
				curr_color = rt_calculate_light(env, curr_obj, d);
			if (!SDL_CLR_CMP(curr_color, 0x0))
				sdl_pixelput(env->sdl->wsurf,
				CONVERT_FROM_CANVAS(i.x, i.y, WIN_X, WIN_Y), curr_color);
		}
}
