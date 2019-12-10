/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:50:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 20:55:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_free(Environment *restrict *env)
{
	size_t	i;

	i = ~0UL;
	if ((*env)->pre_calc_d)
	{
		while (WIN_Y > ++i)
			FREE((*env)->pre_calc_d[i], free);
		FREE((*env)->pre_calc_d, free);
	}
	IFDO(*env && (*env)->sdl, sdl_free(&(*env)->sdl));
	IFDO(*env, FREE((*env)->scene.objs, free));
	IFDO(*env, FREE((*env)->scene.lights, free));
	IFDO(*env, FREE((*env)->frh, free));
	FREE(*env, free);
	tpool_wait(g_threads_pool);
	tpool_destroy(g_threads_pool);
}
