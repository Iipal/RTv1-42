/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:37:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 12:20:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

void	sdl_free(Sdl **restrict sdl)
{
	if (*sdl)
	{
		if ((*sdl)->w)
			SDL_DestroyWindow((*sdl)->w);
		if ((*sdl)->font)
			TTF_CloseFont((*sdl)->font);
		free(*sdl);
	}
	TTF_Quit();
	SDL_Quit();
}
