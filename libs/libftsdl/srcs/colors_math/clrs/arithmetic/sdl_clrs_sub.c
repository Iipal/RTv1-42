/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:59:32 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 13:54:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

Color	sdl_clrs_sub(Color const src, Color const sub)
{
	return ((Color){.c = (t_clr){.r = INRANGE(src.c.r - sub.c.r),
								.g = INRANGE(src.c.g - sub.c.g),
								.b = INRANGE(src.c.b - sub.c.b)} });
}
