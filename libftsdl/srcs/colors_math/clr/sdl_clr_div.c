/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:11:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 23:14:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_clr_div(Color *dst, const float div)
{
	*dst = (Color){
		sdl_clr_inrange(dst->r / div),
		sdl_clr_inrange(dst->g / div),
		sdl_clr_inrange(dst->b / div)};
}
