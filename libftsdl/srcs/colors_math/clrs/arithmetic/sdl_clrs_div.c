/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_div.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:56:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/19 11:23:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clrs_div(Color src, const Color div)
{
	Color	out;

	out = src;
	if (!SDL_CLR_CMP(src.c, 0x0) && !SDL_CLR_CMP(div.c, 0x0))
		out.c = (t_clr){INRANGE(src.c.r / div.c.r),
						INRANGE(src.c.g / div.c.g),
						INRANGE(src.c.b / div.c.b) };
	return (out);
}
