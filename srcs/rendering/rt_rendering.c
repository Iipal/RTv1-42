/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 19:38:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	render(void *arg)
{
	Environment *restrict const	env = ft_memdup(arg, sizeof(Environment));
	Color						clr;
	__v2si						xy;
	int							i;

	i = env->render_range[0] - 1;
	while (env->render_range[1] >= ++i)
		{
			xy = (__v2si) { i / WIN_X, i % WIN_X };
			env->scene.tmax = TMAX;
			env->scene.tmin = TMIN;
			if (env->flags.anti_aliasing)
				clr = rt_anti_aliasing(env, env->flags.anti_aliasing,
					env->pre_calc_d[Y(xy)][X(xy)]);
			else
				clr = rt_raytracing(&env->scene, env->pre_calc_d[Y(xy)][X(xy)],
					env->flags.ambient_light);
			if (clr.hex)
				sdl_pixelput(env->sdl->wsurf, xy, clr);
		}
}

void	rt_rendering(Environment *restrict const env)
{
	const size_t	render_frame = (WIN_X * WIN_Y / g_threads_num);
	size_t			i;

	i = ~0UL;
	printf("render frame: %zu(%d)\n", render_frame, WIN_X * WIN_Y);
	while (g_threads_num > ++i) {
		env->render_range = (__v2si)
			{ render_frame * i, render_frame * (i + 1UL) };
		printf("render range[%3zu]: %7d -> %7d\n", i + 1UL,
			env->render_range[0], env->render_range[1]);
		tpool_add_work(g_threads_pool, render, env);
	}
	tpool_wait(g_threads_pool);
	if (IS_BIT(g_isr_flags, ISR_RENDER_FPS))
		rt_render_fps_counter(&env->flags.fps_text_color, &env->fps.time,
			env->sdl, env->flags.fps_refresh_timer, env->frh);
	if (IS_BIT(g_flags, F_BIT_RLI) && !IS_BIT(g_flags, F_BIT_NCL))
		rt_randomize_lights_intense(env->scene.lights, env->scene.ins_lights,
			env->fps.time.res);
}
