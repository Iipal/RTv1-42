/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_mul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:00:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 19:01:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_clrs_mul(Color *dst, const Color mul)
{
	*dst = (Color){
		sdl_clr_inrange(dst->r * mul.r),
		sdl_clr_inrange(dst->g * mul.g),
		sdl_clr_inrange(dst->b * mul.b)};
}
