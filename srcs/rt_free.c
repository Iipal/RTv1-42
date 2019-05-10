/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:50:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/10 19:19:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_free(Environment **env)
{
	IFDO(*env && (*env)->sdl, sdl_free(&(*env)->sdl));
	IFDO(*env && (*env)->s.objs, FREE((*env)->s.objs, free));
	FREE(*env, free);
	SDL_Quit();
}
