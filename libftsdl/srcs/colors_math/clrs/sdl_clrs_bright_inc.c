/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_bright_inc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:53:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/16 17:55:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clrs_bright_inc(Color clr1,
								const Color clr2,
								const float_t percent)
{
	Color	out;

	out = clr1;
	if (.0f < percent)
		out = (Color) { INRANGE(clr1.r + (clr2.r * percent)),
						INRANGE(clr1.g + (clr2.g * percent)),
						INRANGE(clr1.b + (clr2.b * percent)) };
	return (out);
}
