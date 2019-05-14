/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_div.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:56:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 10:39:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clrs_div(Color src, const Color div)
{
	if (!SDL_CLR_CMP(src, 0x0) && !SDL_CLR_CMP(div, 0x0))
		return ((Color){INRANGE(src.r / div.r),
						INRANGE(src.g / div.g),
						INRANGE(src.b / div.b)});
	return (src);
}
