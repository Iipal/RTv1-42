/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_bright_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:44:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/13 12:18:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clr_bright_dec(Color src, const float_t percent)
{
	Color	out;

	out = src;
	if (.0f < percent)
		out = (Color) { INRANGE(src.r - (src.r * percent)),
						INRANGE(src.g - (src.g * percent)),
						INRANGE(src.b - (src.b * percent)) };
	return (out);
}
