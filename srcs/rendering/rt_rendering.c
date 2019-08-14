/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/13 21:20:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_rendering(Environment *restrict const env)
{
	Color	clr;
	__v2si	i;

	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	Y(i) = WIN_Y;
	while (0 <= --Y(i) && (X(i) = WIN_X))
		while (0 <= --X(i))
		{
			env->scene.tmax = TMAX;
			env->scene.tmin = TMIN;
			if (env->flags.anti_aliasing)
				clr = rt_anti_aliasing(env, env->flags.anti_aliasing,
					env->pre_calc_d[Y(i)][X(i)]);
			else
				clr = rt_raytracing(&env->scene, env->pre_calc_d[Y(i)][X(i)],
					env->flags.ambient_light);
			if (clr.hex)
				sdl_pixelput(env->sdl->wsurf, i, clr);
		}
	if (IS_BIT(g_isr_flags, ISR_RENDER_FPS))
		rt_render_fps_counter(&env->flags.fps_text_color, &env->fps.time,
			env->sdl, env->flags.fps_refresh_timer, env->frh);
	if (IS_BIT(g_flags, F_BIT_RLI) && !IS_BIT(g_flags, F_BIT_NCL))
		rt_randomize_lights_intense(env->scene.lights, env->scene.ins_lights,
			env->fps.time.res);
}
