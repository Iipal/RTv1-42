/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:59:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 23:27:16 by tmaluh           ###   ########.fr       */
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
	uint32_t	*pxls;
	SDL_Event	e;
};

# define SDL    typedef struct s_sdl    Sdl;

SDL;

bool	sdl_init(Sdl *sdl, int32_t width, int32_t height, cstring title);

void	sdl_free(Sdl **sdl);

void	sdl_pixelput(SDL_Surface *surf, int32_t x, int32_t y, Color clr);

#endif
