/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:59:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 17:39:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_H
# define LIBFTSDL_H

# ifdef __APPLE__
#  include "../../frameworks/SDL2.framework/Headers/SDL.h"
# endif
# ifdef __linux__
#  include <SDL2/SDL.h>
# endif

# include "../../libft/includes/libft.h"
# include <stdint.h>

# define E_SURFPXL  " ERROR: Broken SDL_Surface load. ->pixels invalid."

# define COLOR_MAX  255
# define COLOR_MIN  0

struct	s_sdl
{
	SDL_Window	*w;
	SDL_Surface	*wsurf;
	uint32_t	*pxls;
	SDL_Event	e;
};

struct	s_color
{
	int16_t	r;
	int16_t	g;
	int16_t	b;
};

# define SDL typedef struct s_sdl	Sdl;
# define SDL_COLOR	typedef struct s_color	Color;

SDL_COLOR;
SDL;

bool		sdl_init(Sdl *sdl, int32_t width, int32_t height, cstring title);

void		sdl_pixelput(SDL_Surface *surf, int32_t x, int32_t y, Color clr);

Uint8		sdl_clr_inrange(int16_t color);
Uint32		sdl_clr_convert_rgb(Color src);

void		sdl_clrs_add(Color *dst, const Color add);

void		sdl_clr_bright_inc(Color *dst, Uint8 amount);
void		sdl_clr_bright_dec(Color *dst, Uint8 amount);

void		sdl_free(Sdl **sdl);

#endif
