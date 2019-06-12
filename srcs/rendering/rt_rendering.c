/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/12 18:59:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_rendering(Environment *restrict const env)
{
	Color	clr;
	__v2si	i;

	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	Y(i) = -1;
	while (WIN_Y > ++Y(i) && (X(i) = -1))
		while (WIN_X > ++X(i))
		{
			env->tmax = TMAX;
			env->tmin = TMIN;
			clr = rt_raytracing(env, env->pre_calc_d[Y(i)][X(i)]);
			if (clr.hex)
				sdl_pixelput(env->sdl->wsurf, i, clr);
		}
	if (env->isr.is_render_fps)
		rt_render_fps_counter(env);
	if (env->flags.random_lights_intense && !env->flags.no_calc_light)
		rt_randomize_lights_intense(env->scene.lights, env->scene.ins_lights,
				env->fps.time.res);
	SDL_UpdateWindowSurface(env->sdl->w);
}
