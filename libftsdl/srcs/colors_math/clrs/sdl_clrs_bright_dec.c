/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_bright_dec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:49:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/11 23:47:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	*sdl_clrs_bright_dec(Color *dst,
								const Color src,
								const float_t percent)
{
	if (dst && .0f < percent)
		*dst = (Color) {
			INRANGE(dst->r - (src.r * (percent / 100.0f))),
			INRANGE(dst->g - (src.g * (percent / 100.0f))),
			INRANGE(dst->b - (src.b * (percent / 100.0f)))};
	return (dst);
}
