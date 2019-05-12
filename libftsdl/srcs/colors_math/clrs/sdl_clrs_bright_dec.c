/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_bright_dec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:49:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/12 14:04:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clrs_bright_dec(Color clr1,
								const Color clr2,
								const float_t percent)
{
	Color	out;

	out = clr1;
	if (.0f < percent)
		out = (Color) { INRANGE(clr1.r - (clr2.r * (percent / 100.0f))),
						INRANGE(clr1.g - (clr2.g * (percent / 100.0f))),
						INRANGE(clr1.b - (clr2.b * (percent / 100.0f))) };
	return (out);
}
