/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:11:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/12 13:49:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clr_div(Color src, const float_t div)
{
	Color	out;

	out = src;
	if (.0f < div && !SDL_CLR_CMP(src, 0x0))
		out = (Color) { INRANGE(src.r / div),
						INRANGE(src.g / div),
						INRANGE(src.b / div) };
	return (out);
}
