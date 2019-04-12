/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pixelput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:02:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 17:39:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_pixelput(SDL_Surface *surf, int32_t x, int32_t y, Color clr)
{
	int32_t	*pixels;

	pixels = surf->pixels;
	if (0 <= x && 0 <= y && y < surf->h && x < surf->w)
		pixels[y * surf->w + x] = sdl_clr_convert_rgb(clr);
}
