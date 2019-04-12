/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:14:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 17:32:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_clrs_add(Color *dst, const Color add)
{
	*dst = (Color){
		sdl_clr_inrange(dst->r + add.r),
		sdl_clr_inrange(dst->g + add.g),
		sdl_clr_inrange(dst->b + add.b)};
}
