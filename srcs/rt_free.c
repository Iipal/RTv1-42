/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:50:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 16:57:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_free(Enviroment **env)
{
	IFDO((*env)->sdl, FREE((*env)->sdl->win, SDL_DestroyWindow));
	FREE((*env)->sdl, free);
	FREE(*env, free);
	SDL_Quit();
}
