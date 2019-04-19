/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pixelput_canvas.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:32:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/19 12:38:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_pixelput_canvas(SDL_Surface *surf, Dot p, Dot win, Color clr)
{
	int32_t	*pixels;

	if (surf)
	{
		pixels = surf->pixels;
		p = (Dot){p.x + win.x / 2, p.y + win.y / 2};
		if (0 <= p.x && 0 <= p.y && p.y < surf->h && p.x < surf->w)
			pixels[p.y * surf->w + p.x] = sdl_clr_convert_rgb(clr);
	}
}
