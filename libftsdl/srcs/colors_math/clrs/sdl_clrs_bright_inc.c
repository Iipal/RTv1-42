/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_bright_inc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:53:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/13 22:16:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	*sdl_clrs_bright_inc(Color *dst, const Color src, float percent)
{
	if (dst && .0f < percent)
		*dst = (Color) {
			INRANGE(dst->r + (src.r * (percent / 100.0f))),
			INRANGE(dst->g + (src.g * (percent / 100.0f))),
			INRANGE(dst->b + (src.b * (percent / 100.0f)))};
	return (dst);
}
