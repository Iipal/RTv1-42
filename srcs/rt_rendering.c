/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 16:22:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

# define B	0.0005f

void	rt_rendering(Environment *env)
{
	point		p;

	p.y = -1;
	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	while (env->w_size.y > ++(p.y) && (p.x = -1))
		while (env->w_size.x > ++(p.x))
			sdl_pixelput(env->sdl->wsurf, p.x, p.y,
				sdl_clr_convert_rgb(env->color));
	SDL_UpdateWindowSurface(env->sdl->w);
}
