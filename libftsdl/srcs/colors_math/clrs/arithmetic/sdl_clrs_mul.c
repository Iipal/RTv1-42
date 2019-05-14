/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_mul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:00:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 10:39:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clrs_mul(Color src, const Color mul)
{
	if (!SDL_CLR_CMP(src, 0x0) && !SDL_CLR_CMP(mul, 0x0))
		return ((Color){INRANGE(src.r / mul.r),
						INRANGE(src.g / mul.g),
						INRANGE(src.b / mul.b)});
	return (src);
}
