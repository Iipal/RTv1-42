/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:59:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/04 19:04:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_H
# define LIBFTSDL_H

# include "libftsdl_colors_math.h"
# include "libftsdl_macroses.h"
# include "libftsdl_errno.h"

struct		s_sdl
{
	SDL_Window	*w;
	SDL_Surface	*wsurf;
	uiarr		pxls;
	SDL_Event	e;
	TTF_Font	*font;
};

# define SDL typedef struct s_sdl Sdl

SDL;

/*
**	Initialize SDL2.
**	\param sdl: Pointer to already allocated Sdl.
**	\param width: Window width what will created.
**	\param height: Window height what will created.
**	\param title: Title for window.
*/
extern bool	sdl_init(Sdl *sdl,
				const int32_t width,
				const int32_t height,
				const string title);

/*
**	Free all data in Sdl*.
*/
extern void	sdl_free(Sdl **sdl);

/*
**	mlx_pixelput implementation on SDL2 for copy workflow from MLX library.
**	\param surf: Surface in which will set color \param clr.
**	\param x: X position in surface->pixels.
**	\param y: Y position in surface->pixels.
**	\param clr: Color which will set on \param x \param y position.
**
**	Protected from segfault when x && y pixel doesnt exist on Surface,
**	and if Surface doesnt exist too.
*/
extern void	sdl_pixelput(SDL_Surface *surf,
				const Dot p, const Color clr);

SDL_Surface	*sdl_load_image(const char *restrict const path,
				const SDL_PixelFormat *format,
				SDL_Surface *dst);
SDL_Surface	*sdl_load_font(const Sdl *const sdl,
				const char *restrict const text,
				const SDL_Color text_color,
				SDL_Surface *dst);

#endif
