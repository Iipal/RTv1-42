/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pixelput_canvas.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:32:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/11 23:57:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_pixelput_canvas(SDL_Surface *surf, Dot p,
								const Dot win,
								const Color clr)
{
	int32_t	*pixels;

	if (surf)
	{
		p = (Dot){p.x + win.x / 2, p.y + win.y / 2};
		pixels = surf->pixels;
		if (0 <= p.x && 0 <= p.y && p.y < surf->h && p.x < surf->w)
			pixels[p.y * surf->w + p.x] = SDL_CLR_TO_RGB(clr);
	}
}
