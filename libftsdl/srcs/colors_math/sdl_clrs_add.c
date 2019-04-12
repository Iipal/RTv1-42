/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:14:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 16:03:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_clrs_add(SDL_Color *a, const SDL_Color *b)
{
	*a = (SDL_Color){
		sdl_clr_inrange(a->r + b->r),
		sdl_clr_inrange(a->b + b->b),
		sdl_clr_inrange(a->g + b->g), 0};
}
