/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:23:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/10 00:11:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

bool	sdl_init(Sdl *sdl, int32_t width, int32_t height, cstring title)
{
	IFDOR(0 > SDL_Init(SDL_INIT_EVERYTHING), MSGN(SDL_GetError()), false);
	IFDOMR(TTF_GetError(), 0 > TTF_Init(), exit(1), false);
	NO(SDL_GetError(),
		sdl->w = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN), (void)0, 0);
	NO(SDL_GetError(), sdl->wsurf = SDL_GetWindowSurface(sdl->w),
		SDL_DestroyWindow(sdl->w), false);
	IFDOR(!(sdl->pxls = sdl->wsurf->pixels), MSGN(E_SURFPXL), false);
	NO(TTF_GetError(),
		sdl->font = TTF_OpenFont(FPS_FONT, 20), (void)0, false);
	return (true);
}
