/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_mul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:00:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/19 11:23:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clrs_mul(Color src, const Color mul)
{
	Color	out;

	out = src;
	if (!SDL_CLR_CMP(src.c, 0x0) && !SDL_CLR_CMP(mul.c, 0x0))
		out.c = (t_clr){INRANGE(src.c.r * mul.c.r),
						INRANGE(src.c.g * mul.c.g),
						INRANGE(src.c.b * mul.c.b)};
	return (out);
}
