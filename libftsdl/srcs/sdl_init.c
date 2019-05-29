/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:23:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/29 11:42:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline bool	sdl_init(Sdl *sdl,
				const int32_t width,
				const int32_t height,
				const string title)
{
	IFM_F(SDL_GetError(), 0 > SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO));
	IFM_F(TTF_GetError(), 0 > TTF_Init());
	IFM_F(IMG_GetError(), 0 > IMG_Init(IMG_INIT_JPG));
	NOM_F(SDL_GetError(),
		sdl->w = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN));
	NO(SDL_GetError(), sdl->wsurf = SDL_GetWindowSurface(sdl->w),
		SDL_DestroyWindow(sdl->w), false);
	IFDOM(E_SURFPXL, !(sdl->pxls = sdl->wsurf->pixels),
		SDL_DestroyWindow(sdl->w));
	IFDOM(TTF_GetError(), !(sdl->font = TTF_OpenFont(FPS_FONT, 20)),
		SDL_DestroyWindow(sdl->w));
	return (true);
}
