/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pixelput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:02:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 11:53:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_pixelput(SDL_Surface *surf, const Dot p, const Color clr)
{
	if (0 <= X(p) && 0 <= Y(p) && Y(p) < surf->h && X(p) < surf->w)
		((uiarr)(surf->pixels))[Y(p) * surf->w + X(p)] = SDL_CLR_TO_RGB(clr);
}
