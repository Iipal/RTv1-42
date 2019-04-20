/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:37:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/20 12:06:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

void	sdl_free(Sdl **sdl)
{
	IFDO(*sdl, FREE((*sdl)->w, SDL_DestroyWindow));
	IFDO(*sdl, TTF_CloseFont((*sdl)->font));
	FREE(*sdl, free);
	TTF_Quit();
	SDL_Quit();
}
