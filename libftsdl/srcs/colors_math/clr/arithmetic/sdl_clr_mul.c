/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_mul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:14:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/19 11:24:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clr_mul(Color src, const float_t mul)
{
	Color	out;

	out = src;
	if (.0f < mul && !SDL_CLR_CMP(out.c, 0x0))
		out.c = (t_clr){INRANGE(src.c.r * mul),
						INRANGE(src.c.g * mul),
						INRANGE(src.c.b * mul)};
	return (out);
}
