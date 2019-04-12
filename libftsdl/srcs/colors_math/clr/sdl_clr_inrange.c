/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_inrange.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:17:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 19:45:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline Uint8	sdl_clr_inrange(int16_t color)
{
	if (COLOR_MAX < color)
		return (COLOR_MAX);
	else if (COLOR_MIN > color)
		return (COLOR_MIN);
	return (color);
}