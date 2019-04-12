/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clr_bright_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:44:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 16:06:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_clr_bright_dec(SDL_Color *src, float amount)
{
	*src = (SDL_Color) {
		sdl_clr_inrange(src->r / amount),
		sdl_clr_inrange(src->g / amount),
		sdl_clr_inrange(src->b / amount), 0};
}
