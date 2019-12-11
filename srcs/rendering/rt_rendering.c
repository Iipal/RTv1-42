/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/11 13:12:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	render(void *arg)
{
	Environment *restrict const	env = arg;
	__v2si						xy;
	int							i;

	again:
	i = env->render_range.x - 1;
	while (env->render_range.y >= ++i)
	{
		xy = (__v2si) { i % WIN_X, i / WIN_X };
		if (!(0 <= X(xy) && 0 <= Y(xy)
		&& Y(xy) < env->sdl->wsurf->h && X(xy) < env->sdl->wsurf->w))
			continue ;
		env->scene.tmax = TMAX;
		env->scene.tmin = TMIN;
		sdl_pixelput(env->sdl->wsurf, xy,
			env->render_fn(env, env->pre_calc_d[Y(xy)][X(xy)]));
	}
	goto again;
}

void	rt_render_threads_create(Environment **envs)
{
	size_t	i;

	i = ~0UL;
	while (g_threads_num > ++i)
		tpool_add_work(g_threads_pool, render, envs[i]);
}
