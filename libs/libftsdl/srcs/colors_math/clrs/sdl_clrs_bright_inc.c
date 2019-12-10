/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_bright_inc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:53:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 12:02:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

Color	sdl_clrs_bright_inc(Color const c1, Color const c2, float_t const per)
{
	Color	out;

	out = c1;
	if (.0f < per)
		out.c = (t_clr){INRANGE(c1.c.r + (c2.c.r * per)),
						INRANGE(c1.c.g + (c2.c.g * per)),
						INRANGE(c1.c.b + (c2.c.b * per))};
	return (out);
}
