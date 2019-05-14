/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:59:32 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 10:40:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline Color	sdl_clrs_sub(Color src, const Color sub)
{
	return ((Color){INRANGE(src.r - sub.r),
					INRANGE(src.g - sub.g),
					INRANGE(src.b - sub.b)});
}
