/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 22:08:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_rendering(Environment *const env)
{
	Color	clr;
	Dot		i;

	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	Y(i) = RT_CANVAS_STARTY;
	while (RT_CANVAS_ENDY > ++Y(i) && (X(i) = RT_CANVAS_STARTX))
		while (RT_CANVAS_ENDX > ++X(i))
		{
			env->t_max = TMAX;
			env->t_min = TMIN;
			clr = rt_raytracing(env, (Vector){X(i) * WIN_X / (1000.0f * WIN_X),
											Y(i) * WIN_Y / (1000.0f * WIN_Y),
											env->flags.viewport_scale});
			if (clr.hex)
				sdl_pixelput(env->sdl->wsurf,
					CONVERT_FROM_CANVAS(X(i), Y(i), WIN_X, WIN_Y), clr);
		}
	IFDO(env->isr.is_render_fps, rt_render_fps_counter(env));
	SDL_UpdateWindowSurface(env->sdl->w);
}
