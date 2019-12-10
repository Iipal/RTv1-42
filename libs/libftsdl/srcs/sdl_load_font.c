/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_load_font.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:15:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 12:24:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

SDL_Surface	*sdl_load_font(const Sdl *restrict sdl,
				const char *restrict text,
				SDL_Color text_color)
{
	SDL_Surface	*temp;
	SDL_Surface	*out;

	out = NULL;
	if (!(temp = TTF_RenderText_Solid(sdl->font, text, text_color)))
	{
		SDL_Log("%s\n", TTF_GetError());
		return out;
	}
	if (!(out = SDL_ConvertSurface(temp, sdl->wsurf->format, 0)))
		SDL_Log("%s\n", SDL_GetError());
	SDL_FreeSurface(temp);
	return (out);
}
