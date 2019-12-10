/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_load_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:05:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 12:22:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

SDL_Surface	*sdl_load_image(const char *restrict path,
				const SDL_PixelFormat *restrict format)
{
	SDL_Surface	*temp;
	SDL_Surface	*out;

	out = NULL;
	if (!(temp = IMG_Load(path)))
	{
		SDL_Log("%s\n", TTF_GetError());
		return (out);
	}
	if (!(out = SDL_ConvertSurface(temp, format, 0)))
		SDL_Log("%s\n", SDL_GetError());
	SDL_FreeSurface(temp);
	return (out);
}
