/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:09:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 15:48:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTS_H
# define RTV1_STRUCTS_H

# include "libft.h"

# ifdef __APPLE__
#  include "SDL.h"
# endif

# ifdef __linux__
#  include <SDL2/SDL.h>
# endif

# define IARR   typedef int32_t*    iarr
# define ITAB   typedef int32_t**   itab
# define UIARR  typedef uint32_t*   uiarr
# define UINT   typedef uint32_t    uint

IARR;
ITAB;
UIARR;
UINT;

struct	s_fpoint
{
	float	x;
	float	y;
};

# define FPOINT typedef struct s_fpoint fpoint

FPOINT;

struct	s_point
{
	int32_t	x;
	int32_t	y;
};

# define POINT typedef struct s_point   point

POINT;

struct	s_sdl
{
	SDL_Window		*win;
	SDL_Surface		*win_surf;
	uiarr			pixels;
	SDL_Event		e;
};

# define SDL typedef struct s_sdl   Sdl

SDL;

struct	s_enviroment
{
	Sdl	*sdl;
};

# define ENV typedef struct s_enviroment    Env

ENV;

#endif
