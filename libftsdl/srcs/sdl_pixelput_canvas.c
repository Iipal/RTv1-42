/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_pixelput_canvas.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:32:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 12:12:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline void	sdl_pixelput_canvas(SDL_Surface *surf, Dot p,
							const Dot win_size,
							const Color clr)
{
	p = (Dot){p.x + win_size.x / 2, p.y + win_size.y / 2};
	sdl_pixelput(surf, p, clr);
}
