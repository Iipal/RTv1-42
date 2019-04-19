/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pixelput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:02:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/19 12:38:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_pixelput(SDL_Surface *surf, Dot p, Color clr)
{
	int32_t	*pixels;

	if (surf)
	{
		pixels = surf->pixels;
		if (0 <= p.x && 0 <= p.y && p.y < surf->h && p.x < surf->w)
			pixels[p.y * surf->w + p.x] = sdl_clr_convert_rgb(clr);
	}
}
