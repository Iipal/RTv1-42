/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:59:32 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/13 09:49:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	*sdl_clrs_sub(Color *dst, const Color sub)
{
	*dst = (Color){
		sdl_clr_inrange(dst->r - sub.r),
		sdl_clr_inrange(dst->g - sub.g),
		sdl_clr_inrange(dst->b - sub.b)};
	return (dst);
}
