/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_inrange.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:17:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 16:30:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline Uint8	sdl_clr_inrange(Uint8 color)
{
	int16_t	increase_color_range;

	increase_color_range = (int16_t)color;
	if (COLOR_MAX < increase_color_range)
		return (COLOR_MAX);
	return (color);
}
