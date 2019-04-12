/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:11:00 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 23:11:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_clr_sub(Color *dst, const int16_t sub)
{
	*dst = (Color){
		sdl_clr_inrange(dst->r - sub),
		sdl_clr_inrange(dst->g - sub),
		sdl_clr_inrange(dst->b - sub)};
}
