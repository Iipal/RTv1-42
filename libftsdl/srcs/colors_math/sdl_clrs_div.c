/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_div.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:56:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 19:44:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_clrs_div(Color *dst, const Color div)
{
	*dst = (Color){
		sdl_clr_inrange(dst->r / div.r),
		sdl_clr_inrange(dst->g / div.g),
		sdl_clr_inrange(dst->b / div.b)};
}
