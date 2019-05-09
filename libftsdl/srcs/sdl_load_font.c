/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_load_font.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:15:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/10 00:11:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

SDL_Surface	*sdl_optimize_font_load(string text, SDL_Color text_color,
	TTF_Font *font, SDL_PixelFormat *format)
{
	SDL_Surface	*optimize_out;
	SDL_Surface	*temp_load;

	temp_load = NULL;
	optimize_out = NULL;
	NO(TTF_GetError(),
		temp_load = TTF_RenderText_Solid(font, text, text_color),
		exit(EXIT_FAILURE), NULL);
	NO(SDL_GetError(),
		optimize_out = SDL_ConvertSurface(temp_load, format, 0),
		exit(EXIT_FAILURE), NULL);
	SDL_FreeSurface(temp_load);
	return (optimize_out);
}
