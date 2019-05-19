/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_bright_inc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:53:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/19 11:22:15 by tmaluh           ###   ########.fr       */
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
		out.c = (t_clr){INRANGE(clr1.c.r + (clr2.c.r * percent)),
						INRANGE(clr1.c.g + (clr2.c.g * percent)),
						INRANGE(clr1.c.b + (clr2.c.b * percent))};
	return (out);
}
