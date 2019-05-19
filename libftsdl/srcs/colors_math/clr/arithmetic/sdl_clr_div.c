/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:11:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/19 11:24:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clr_div(Color src, const float_t div)
{
	Color	out;

	out = src;
	if (.0f < div && !SDL_CLR_CMP(out.c, 0x0))
		out.c = (t_clr){INRANGE(src.c.r / div),
						INRANGE(src.c.g / div),
						INRANGE(src.c.b / div)};
	return (out);
}
