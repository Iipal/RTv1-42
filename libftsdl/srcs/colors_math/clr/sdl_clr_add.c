/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:08:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 23:10:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_clr_add(Color *dst, const int16_t add)
{
	*dst = (Color){
		sdl_clr_inrange(dst->r + add),
		sdl_clr_inrange(dst->g + add),
		sdl_clr_inrange(dst->b + add)};
}
