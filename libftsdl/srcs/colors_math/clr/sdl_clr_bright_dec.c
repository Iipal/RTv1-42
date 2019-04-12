/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_bright_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:44:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 23:16:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_clr_bright_dec(Color *dst, float amount)
{
	if (.0f < amount)
	{
		if (!dst->r && !dst->b && !dst->g)
			*dst = (Color) {amount, amount, amount};
		else
		{
			if (1.0f > amount)
				amount += 1.0f;
			sdl_clr_div(dst, amount);
		}
	}
}
