/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_mul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:00:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/14 16:58:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	*sdl_clrs_mul(Color *dst, const Color mul)
{
	*dst = (Color){
		sdl_clr_inrange((dst->r && mul.r) ? (dst->r * mul.r) : dst->r),
		sdl_clr_inrange((dst->g && mul.g) ? (dst->g * mul.g) : dst->g),
		sdl_clr_inrange((dst->b && mul.b) ? (dst->b * mul.b) : dst->b)};
	return (dst);
}
