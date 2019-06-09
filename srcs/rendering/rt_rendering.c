/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/09 14:44:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_rendering(Environment *restrict const env)
{
	Color			clr;
	__v2df			i;

	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	Y(i) = RT_CANVAS_STARTY;
	while (RT_CANVAS_ENDY > ++Y(i) && (X(i) = RT_CANVAS_STARTX))
		while (RT_CANVAS_ENDX > ++X(i))
		{
			env->tmax = TMAX;
			env->tmin = TMIN;
			clr = rt_raytracing(env, (__v4df){X(i) * WIN_X / (1000.0 * WIN_X),
											Y(i) * WIN_Y / (1000.0 * WIN_Y),
											env->flags.viewport_scale});
			if (clr.hex)
				sdl_pixelput(env->sdl->wsurf,
					CONVERT_FROM_CANVAS(X(i), Y(i), WIN_X, WIN_Y), clr);
		}
	if (env->isr.is_render_fps)
		rt_render_fps_counter(env);
	if (env->flags.random_lights_intense && !env->flags.no_calc_light)
		rt_randomize_lights_intense(env->scene.lights, env->scene.ins_lights,		env->fps.time.res);
	SDL_UpdateWindowSurface(env->sdl->w);
}
