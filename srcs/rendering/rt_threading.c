/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_threading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 22:17:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 22:27:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

Environment	**rt_prepare_threading(Environment *restrict const env)
{
	const size_t	render_frame = (WIN_X * WIN_Y / g_threads_num);
	render_fnptr	render_fn;
	Environment		**out;
	size_t			i;

	i = ~0UL;
	if (env->flags.anti_aliasing)
		render_fn = rt_anti_aliasing;
	else
		render_fn = rt_raytracing;
	out = ft_memalloc(g_threads_num * sizeof(Environment*));
	while (g_threads_num > ++i) {
		out[i] = ft_memdup(env, sizeof(Environment));
		out[i]->render_range = (struct s_2si)
			{ render_frame * i, render_frame * (i + 1UL) };
		out[i]->render_fn = render_fn;
	}
	return (out);
}

void		rt_free_threading(Environment **env_dups)
{
	size_t	i;

	i = ~0UL;
	while (g_threads_num > ++i)
		free(env_dups[i]);
	free(env_dups);
}
