/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_bright_inc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:52:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 20:13:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_clr_bright_inc(Color *dst, float amount)
{
	if (.0f < amount)
	{
		if (!dst->r && !dst->b && !dst->g)
			*dst = (Color) {amount, amount, amount};
		else
		{
			if (1.0f > amount)
				amount += 1.0f;
			*dst = (Color){
				sdl_clr_inrange(dst->r * amount),
				sdl_clr_inrange(dst->g * amount),
				sdl_clr_inrange(dst->b * amount)};
		}
	}
}