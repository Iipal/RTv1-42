/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_bright_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:44:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/12 13:41:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clr_bright_dec(Color src, const float_t percent)
{
	Color	out;

	out = src;
	if (.0f < percent)
		out = (Color) {
			INRANGE((!src.r ? 1 : src.r) - (src.r * (percent / 100.0f))),
			INRANGE((!src.g ? 1 : src.g) - (src.g * (percent / 100.0f))),
			INRANGE((!src.b ? 1 : src.b) - (src.b * (percent / 100.0f)))};
	return (out);
}
