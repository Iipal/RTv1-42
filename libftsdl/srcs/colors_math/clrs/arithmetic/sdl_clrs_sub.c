/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:59:32 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/19 11:22:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clrs_sub(Color src, const Color sub)
{
	return ((Color){.c.r = INRANGE(src.c.r - sub.c.r),
					.c.g = INRANGE(src.c.g - sub.c.g),
					.c.b = INRANGE(src.c.b - sub.c.b)});
}
