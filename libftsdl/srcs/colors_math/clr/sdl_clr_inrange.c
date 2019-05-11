/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_inrange.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:17:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/11 23:46:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Uint8	sdl_clr_inrange(const int16_t color)
{
	if (COLOR_MAX < color)
		return (COLOR_MAX);
	else if (COLOR_MIN > color)
		return (COLOR_MIN);
	return (color);
}
