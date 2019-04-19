/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_rgb_convert_clr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:37:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/18 15:49:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_rgb_convert_clr(Uint32 src)
{
	Color	out;

	out = (Color){src >> 16, (src >> 8) & 0xff, src & 0xff};
	return (out);
}
