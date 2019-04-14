/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_isoneof.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:42:37 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/14 15:45:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

inline bool	sdl_clrs_isoneof(const Color c1, const Color c2)
{
	return (c1.r == c2.r || c1.g == c2.g || c1.b == c2.b);
}
