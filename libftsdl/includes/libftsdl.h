/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:59:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/11 22:36:37 by tmaluh           ###   ########.fr       */
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

struct	s_sdl
{
	SDL_Window	*w;
	SDL_Surface	*wsurf;
	uint32_t	*pxls;
	SDL_Event	e;
};

# define SDL typedef struct s_sdl	Sdl;

SDL;

bool	sdl_init(Sdl *sdl, int32_t width, int32_t height, cstring title);

void	sdl_pixelput(SDL_Surface *surf, int32_t x, int32_t y, uint32_t color);

void	sdl_free(Sdl **sdl);

#endif
