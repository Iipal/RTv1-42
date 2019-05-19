/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_bright_inc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:52:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/19 11:25:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clr_bright_inc(Color src, const float_t percent)
{
	Color	out;

	out = src;
	if (.0f < percent)
		out.c = (t_clr){INRANGE(src.c.r + (src.c.r * percent)),
						INRANGE(src.c.g + (src.c.g * percent)),
						INRANGE(src.c.b + (src.c.b * percent))};
	return (out);
}
