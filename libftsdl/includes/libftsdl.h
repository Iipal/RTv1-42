/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:59:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/18 15:47:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_H
# define LIBFTSDL_H

# include "libftsdl_colors_math.h"

# define E_SURFPXL  " ERROR: Broken SDL_Surface load. ->pixels invalid."

struct	s_sdl
{
	SDL_Window	*w;
	SDL_Surface	*wsurf;
	uiarr		pxls;
	SDL_Event	e;
};

# define SDL    typedef struct s_sdl    Sdl;

SDL;

/*
**	Initialize SDL2.
**	\param sdl: Pointer to already allocated Sdl.
**	\param width: Window width what will created.
**	\param height: Window height what will created.
**	\param title: Title for window.
*/
bool	sdl_init(Sdl *sdl, int32_t width, int32_t height, cstring title);

/*
**	Free all data in Sdl*.
*/
void	sdl_free(Sdl **sdl);

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
void	sdl_pixelput(SDL_Surface *surf, Dot p, Color clr);

void	sdl_pixelput_canvas(SDL_Surface *surf, Dot p, Dot win, Color clr);

#endif
