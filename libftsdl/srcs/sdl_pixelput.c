/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pixelput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:02:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 20:06:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

void	sdl_pixelput(SDL_Surface *surface, int32_t x, int32_t y, int64_t color)
{
	int64_t	*pixels;

	pixels = surface->pixels;
	if (0 < x && 0 < y && surface->h < y && surface->w < x)
		pixels[y * surface->w + x] = color;
}
