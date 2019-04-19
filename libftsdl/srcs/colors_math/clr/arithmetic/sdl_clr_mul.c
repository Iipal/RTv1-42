/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_mul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:14:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/19 16:34:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	*sdl_clr_mul(Color *dst, const float mul)
{
	*dst = (Color){
		sdl_clr_inrange((dst->r && .0f < mul) ? (dst->r * mul) : dst->r),
		sdl_clr_inrange((dst->g && .0f < mul) ? (dst->r * mul) : dst->g),
		sdl_clr_inrange((dst->b && .0f < mul) ? (dst->r * mul) : dst->b)};
	return (dst);
}
