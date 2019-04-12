/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_bright_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:44:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 17:37:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_clr_bright_dec(Color *dst, Uint8 amount)
{
	if (1 < amount)
	{
		if (!dst->r && !dst->b && !dst->g)
			*dst = (Color) {amount, amount, amount};
		else
			*dst = (Color){
				sdl_clr_inrange(dst->r / amount),
				sdl_clr_inrange(dst->g / amount),
				sdl_clr_inrange(dst->b / amount)};
	}
}
