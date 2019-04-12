/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_bright_inc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:52:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 16:18:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_clr_bright_inc(SDL_Color *src, float amount)
{
	if (0 == src->r && 0 == src->b && 0 == src->g)
		*src = (SDL_Color){1, 1, 1, 0};
	else
		*src = (SDL_Color) {
			sdl_clr_inrange(src->r * amount),
			sdl_clr_inrange(src->g * amount),
			sdl_clr_inrange(src->b * amount), 0};
}
