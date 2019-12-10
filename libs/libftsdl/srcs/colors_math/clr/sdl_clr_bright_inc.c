/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_bright_inc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:52:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 12:25:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

Color	sdl_clr_bright_inc(Color const src, float_t const percent)
{
	Color	out;

	out = src;
	if (.0f < percent)
		out.c = (t_clr){INRANGE(src.c.r + (src.c.r * percent)),
						INRANGE(src.c.g + (src.c.g * percent)),
						INRANGE(src.c.b + (src.c.b * percent))};
	return (out);
}
