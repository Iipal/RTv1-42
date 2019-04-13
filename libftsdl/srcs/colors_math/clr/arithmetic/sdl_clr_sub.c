/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:11:00 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/13 09:48:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	*sdl_clr_sub(Color *dst, const int16_t sub)
{
	*dst = (Color){
		sdl_clr_inrange(dst->r - sub),
		sdl_clr_inrange(dst->g - sub),
		sdl_clr_inrange(dst->b - sub)};
	return (dst);
}
