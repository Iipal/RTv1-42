/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:14:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 13:54:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

Color	sdl_clr_sub(Color const src, float_t const sub)
{
	return ((Color){.c = (t_clr){.r = INRANGE(src.c.r - sub),
								.g = INRANGE(src.c.g - sub),
								.b = INRANGE(src.c.b - sub)} });
}
