/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_div.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:56:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/14 16:58:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	*sdl_clrs_div(Color *dst, const Color div)
{
	*dst = (Color){
		sdl_clr_inrange((dst->r && div.r) ? (dst->r / div.r) : dst->r),
		sdl_clr_inrange((dst->g && div.g) ? (dst->g / div.g) : dst->g),
		sdl_clr_inrange((dst->b && div.b) ? (dst->b / div.b) : dst->b)};
	return (dst);
}
