/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:23:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/12 13:36:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_raytracing(Environment *env)
{
	Dot		i;
	t_vec	d;
	Object	*curr_obj;
	Color	curr_color;

	i.y = RT_CANVAS_STARTY;
	while (RT_CANVA_ENDY > ++(i.y) && (i.x = RT_CANVAS_STARTX))
		while (RT_CANVAS_ENDX > ++(i.x))
		{
			env->s.cobj = env->t_max;
			curr_color = CLR_BLACK;
			d = (t_vec) {i.x * WIN_X / (1000.0 * WIN_X),
				i.y * WIN_Y / (1000.0 * WIN_Y), 1.0};
			curr_obj = rt_closest_inter(env->s.cam.pos, d, env, false);
			if (curr_obj)
				curr_color = rt_calculate_light(env, curr_obj, d);
			if (!SDL_CLR_CMP(curr_color, 0x0))
				sdl_pixelput_canvas(env->sdl->wsurf,
					(Dot){i.x, i.y}, (Dot){WIN_X, WIN_Y}, curr_color);
		}
}
