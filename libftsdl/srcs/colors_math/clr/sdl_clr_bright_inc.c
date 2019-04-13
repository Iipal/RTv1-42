/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_bright_inc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:52:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/13 22:16:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	*sdl_clr_bright_inc(Color *dst, float percent)
{
	if (dst && .0f < percent)
		*dst = (Color) {
			INRANGE((dst->r ? dst->r : 1) + (dst->r * (percent / 100.0f))),
			INRANGE((dst->g ? dst->g : 1) + (dst->g * (percent / 100.0f))),
			INRANGE((dst->b ? dst->b : 1) + (dst->b * (percent / 100.0f)))};
	return (dst);
}
