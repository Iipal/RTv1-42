/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/24 18:46:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	draw_from_l_to_obj(Environment *restrict const env)
{
	__v2df	uv_l, uv_o;
	Light const *const l = env->scene.lights;
	Object const *const o = env->scene.objs;

	for (ssize_t i = env->scene.ins_lights; 0 <= --i;) {
		for (ssize_t j = env->scene.ins_objs; 0 <= --j;) {
			double const	dist_to_obj = v_len(l[i].pos - o[i].pos);

			uv_l = (__v2df){X(l[i].pos) / (!Z(l[i].pos) ? 1.0 : Z(l[i].pos)),
						Y(l[i].pos) / (!Z(l[i].pos) ? 1.0 : Z(l[i].pos))};
			uv_o = (__v2df){X(o[j].pos) / (!Z(o[j].pos) ? 1.0 : Z(o[j].pos)),
						Y(o[j].pos) / (!Z(o[j].pos) ? 1.0 : Z(o[j].pos))};

			uv_l = D_FROM_CANVAS(X(uv_l) * dist_to_obj,
								Y(uv_l) * dist_to_obj, WIN_X, WIN_Y);
			uv_o = D_FROM_CANVAS(X(uv_o) * dist_to_obj,
								Y(uv_o) * dist_to_obj, WIN_X, WIN_Y);

			wu_draw_line(uv_l, uv_o, env->sdl->wsurf);
		}
	}
}

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
	draw_from_l_to_obj(env);
}
