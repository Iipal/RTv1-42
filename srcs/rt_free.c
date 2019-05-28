/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:50:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/28 19:09:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_free(Environment *restrict *env)
{
	IFDO(*env && (*env)->sdl, sdl_free(&(*env)->sdl));
	IFDO(*env && (*env)->scene.objs, FREE((*env)->scene.objs, free));
	IFDO(*env && (*env)->scene.lights, FREE((*env)->scene.lights, free));
	FREE(*env, free);
}
