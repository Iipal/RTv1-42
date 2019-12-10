/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:23:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 19:16:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

bool	sdl_init(Sdl *restrict sdl,
			int32_t width,
			int32_t height,
			const char *restrict title)
{
	if (0 > SDL_Init(SDL_INIT_EVERYTHING))
	{
		SDL_Log("%s\n", SDL_GetError());
		return (false);
	}
	if (0 > TTF_Init())
	{
		SDL_Log("%s\n", TTF_GetError());
		return (false);
	}
	if (!(sdl->font = TTF_OpenFont(FPS_FONT, FPS_FONT_SIZE)))
	{
		SDL_Log("%s\n", TTF_GetError());
		return (false);
	}
	if (0 > IMG_Init(IMG_INIT_JPG))
	{
		SDL_Log("%s\n", IMG_GetError());
		return (false);
	}
	if (!sdl_create_window(sdl, width, height, title))
		return (false);
	return (true);
}
