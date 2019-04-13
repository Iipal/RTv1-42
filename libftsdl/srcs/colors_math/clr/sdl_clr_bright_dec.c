/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_bright_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:44:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/13 22:16:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	*sdl_clr_bright_dec(Color *dst, float percent)
{
	if (dst && .0f < percent)
		*dst = (Color) {
			INRANGE((!dst->r ? 1 : dst->r) - (dst->r * (percent / 100.0f))),
			INRANGE((!dst->g ? 1 : dst->g) - (dst->g * (percent / 100.0f))),
			INRANGE((!dst->b ? 1 : dst->b) - (dst->b * (percent / 100.0f)))};
	return (dst);
}
