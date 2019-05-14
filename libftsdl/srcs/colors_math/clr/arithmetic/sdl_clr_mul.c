/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_mul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:14:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 10:38:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clr_mul(Color src, const float_t mul)
{
	if (.0f < mul && !SDL_CLR_CMP(src, 0x0))
		return ((Color){INRANGE(src.r * mul),
						INRANGE(src.g * mul),
						INRANGE(src.b * mul)});
	return (src);
}
