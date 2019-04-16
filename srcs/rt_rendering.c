/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/16 17:29:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

# define INC	10

void	rt_rendering(Environment *env)
{
	Dot	p;

	p.y = -1;
	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	env->color = (Color){230, 0, 100};
	while (WIN_Y > ++(p.y) && (p.x = -1))
	{
		while (WIN_X > ++(p.x))
		{
			sdl_pixelput(env->sdl->wsurf, p.x, p.y, env->color);
		}
	}
	SDL_UpdateWindowSurface(env->sdl->w);
}
