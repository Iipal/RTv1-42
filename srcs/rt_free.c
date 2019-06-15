/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:50:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/15 23:35:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_free(Environment *restrict *env)
{
	size_t	i;

	i = ~0ULL;
	if ((*env)->pre_calc_d)
	{
		while (WIN_Y > ++i)
			FREE((*env)->pre_calc_d[i], free);
		FREE((*env)->pre_calc_d, free);
	}
	IFDO(*env && (*env)->sdl, sdl_free(&(*env)->sdl));
	IFDO(*env && (*env)->scene.objs, FREE((*env)->scene.objs, free));
	IFDO(*env && (*env)->scene.lights, FREE((*env)->scene.lights, free));
	FREE(*env, free);
}
