/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_bright_inc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:52:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/13 09:51:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline void	sdl_clr_bright_inc(Color *dst, float percent)
{
	if (.0f < percent)
	{
		if (!dst->r && !dst->b && !dst->g)
			*dst = (Color) {1, 1, 1};
		else
			*dst = (Color){
				INRANGE(dst->r + (dst->r * (percent / 100))),
				INRANGE(dst->g + (dst->g * (percent / 100))),
				INRANGE(dst->b + (dst->b * (percent / 100)))
			};
	}
}
