/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 17:39:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

# define B	2

void	rt_rendering(Environment *env)
{
	point		p;

	p.y = -1;
	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	while (env->w_size.y > ++(p.y) && (p.x = -1))
		while (env->w_size.x > ++(p.x))
			sdl_pixelput(env->sdl->wsurf, p.x, p.y, env->color);
	SDL_UpdateWindowSurface(env->sdl->w);
}
