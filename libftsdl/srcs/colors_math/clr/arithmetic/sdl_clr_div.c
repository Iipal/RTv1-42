/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:11:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/19 13:19:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	*sdl_clr_div(Color *dst, const float div)
{
	*dst = (Color){
		sdl_clr_inrange((dst->r && .0f != div) ? (dst->r / div) : dst->r),
		sdl_clr_inrange((dst->g && .0f != div) ? (dst->r / div) : dst->g),
		sdl_clr_inrange((dst->b && .0f != div) ? (dst->r / div) : dst->b)};
	return (dst);
}
