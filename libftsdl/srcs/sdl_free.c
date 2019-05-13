/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:37:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/13 15:24:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

void	sdl_free(Sdl **sdl)
{
	IFDO(*sdl, FREE((*sdl)->w, SDL_DestroyWindow));
	IFDO(*sdl, FREE((*sdl)->font, TTF_CloseFont));
	FREE(*sdl, free);
	TTF_Quit();
	SDL_Quit();
}
