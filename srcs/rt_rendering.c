/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/14 18:40:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

# define INC	10

void	rt_rendering(Environment *env)
{
	point		p;
	env->color = (Color){0xff, 0x80, 0x00};
	Color		c1 = {0x21, 0x42, 0x84};
	Color		c2 = {0x00, 0x80, 0xff};
	Color		*g;
	static int8_t a;

	p.y = -1;
	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	g = sdl_clrs_gradient(env->color, c1, env->w_size.y);
	if (2 < a)
		a = 0;
	while (env->w_size.y > ++(p.y) && (p.x = -1))
	{
		Color	*g2 = sdl_clrs_gradient(g[p.y], c2, env->w_size.x);
		while (env->w_size.x > ++(p.x))
		{
			Color	c = g[p.y];
			if (!a) sdl_clrs_bright_inc(&c, g2[p.x], INC);
			else if (a == 1) sdl_clrs_bright_dec(&c, g2[p.x], INC);
			sdl_pixelput(env->sdl->wsurf, p.x, p.y, c);
		}
		FREE(g2, free);
	}
	FREE(g, free);
	SDL_Delay(500);
	SDL_UpdateWindowSurface(env->sdl->w);
	++a;
}
