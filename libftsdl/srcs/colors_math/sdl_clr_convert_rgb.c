/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_convert_rgb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:00:05 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 17:07:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline Uint32	sdl_clr_convert_rgb(Color src)
{
	return (src.r << 16 | src.g << 8 | src.b);
}
