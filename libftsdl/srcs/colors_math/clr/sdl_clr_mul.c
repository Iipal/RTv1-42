/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_mul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:14:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 23:15:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_clr_mul(Color *dst, const float mul)
{
	*dst = (Color){
		sdl_clr_inrange(dst->r * mul),
		sdl_clr_inrange(dst->g * mul),
		sdl_clr_inrange(dst->b * mul)};
}
