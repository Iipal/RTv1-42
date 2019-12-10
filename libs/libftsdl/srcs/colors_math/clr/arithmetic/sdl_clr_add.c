/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:14:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 13:53:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

Color	sdl_clr_add(Color const src, float_t const add)
{
	return ((Color){.c = (t_clr){.r = INRANGE(src.c.r + add),
								.g = INRANGE(src.c.g + add),
								.b = INRANGE(src.c.b + add)} });
}
