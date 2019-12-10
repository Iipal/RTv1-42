/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_bright_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:44:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 12:08:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

Color	sdl_clr_bright_dec(Color const src, float_t const percent)
{
	Color	out;

	out = src;
	if (.0f < percent)
		out.c = (t_clr){INRANGE(src.c.r - (src.c.r * percent)),
						INRANGE(src.c.g - (src.c.g * percent)),
						INRANGE(src.c.b - (src.c.b * percent))};
	return (out);
}
