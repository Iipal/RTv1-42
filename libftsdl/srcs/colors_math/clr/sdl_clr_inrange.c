/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_inrange.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:17:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 11:51:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline int32_t	sdl_clr_inrange(int32_t color)
{
	if (COLOR_MAX < color)
		return (COLOR_MAX);
	if (COLOR_MIN > color)
		return (COLOR_MIN);
	return (color);
}
