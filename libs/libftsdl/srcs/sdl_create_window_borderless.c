/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_create_window_borderless.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:16:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 12:20:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

bool	sdl_create_window_borderless(Sdl *restrict sdl,
			int32_t width,
			int32_t height,
			const char *restrict title)
{
	if (sdl->w)
		SDL_DestroyWindow(sdl->w);
	if (!(sdl->w = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_BORDERLESS)))
		return (false);
	if (!(sdl->wsurf = SDL_GetWindowSurface(sdl->w)))
	{
		SDL_DestroyWindow(sdl->w);
		return (false);
	}
	if (!(sdl->pxls = sdl->wsurf->pixels))
	{
		SDL_DestroyWindow(sdl->w);
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s\n", E_SURFPXL);
		return (false);
	}
	return (true);
}
