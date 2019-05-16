/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/16 17:25:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_rendering(Environment *env)
{
	Dot		i;
	Color	clr;

	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	i.y = RT_CANVAS_STARTY;
	while (RT_CANVAS_ENDY > ++(i.y) && (i.x = RT_CANVAS_STARTX))
		while (RT_CANVAS_ENDX > ++(i.x))
		{
			env->t_max = TMAX;
			env->t_min = TMIN;
			clr = rt_raytracing(env, (Vector){i.x * WIN_X / (1000.0f * WIN_X),
											i.y * WIN_Y / (1000.0f * WIN_Y),
											env->flags.viewport_scale});
			if (!SDL_CLR_CMP(clr, RGB_BLACK))
				sdl_pixelput(env->sdl->wsurf,
					CONVERT_FROM_CANVAS(i.x, i.y, WIN_X, WIN_Y), clr);
		}
	IFDO(env->isr.is_render_fps, rt_render_fps_counter(env));
	SDL_UpdateWindowSurface(env->sdl->w);
}
