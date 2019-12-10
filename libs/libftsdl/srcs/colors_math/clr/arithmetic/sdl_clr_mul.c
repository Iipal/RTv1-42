/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_mul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:14:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 12:09:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

Color	sdl_clr_mul(Color const src, float_t const mul)
{
	Color	out;

	out = src;
	if (.0f < mul && !SDL_CLR_CMP(out.c, 0x0))
		out.c = (t_clr){INRANGE(src.c.r * mul),
						INRANGE(src.c.g * mul),
						INRANGE(src.c.b * mul)};
	return (out);
}
