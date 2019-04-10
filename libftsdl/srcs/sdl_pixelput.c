/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pixelput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:02:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 22:04:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

void	sdl_pixelput(SDL_Surface *surf, int32_t x, int32_t y, uint32_t color)
{
	int32_t	*pixels;

	pixels = surf->pixels;
	if (0 <= x && 0 <= y && y < surf->h && x < surf->w)
		pixels[y * surf->w + x] = color;
}
