/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_load_font.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:15:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/29 11:29:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

SDL_Surface	*sdl_load_font(const Sdl *const sdl,
				const char *restrict const text,
				const SDL_Color text_color,
				SDL_Surface *dst)
{
	SDL_Surface	*temp;

	temp = NULL;
	dst = NULL;
	NOM_R(TTF_GetError(),
		temp = TTF_RenderText_Solid(sdl->font, text, text_color), NULL);
	NOM_R(SDL_GetError(),
		dst = SDL_ConvertSurface(temp, sdl->wsurf->format, 0), NULL);
	SDL_FreeSurface(temp);
	return (dst);
}
