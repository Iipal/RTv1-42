/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:14:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 13:54:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

Color	sdl_clrs_add(Color const src, Color const add)
{
	return ((Color){.c = (t_clr){.r = INRANGE(src.c.r + add.c.r),
								.g = INRANGE(src.c.g + add.c.g),
								.b = INRANGE(src.c.b + add.c.b)} });
}
