/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/13 23:22:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

# define INC	5

void	rt_rendering(Environment *env)
{
	point		p;
	Color		c1 = {0x53, 0x42, 0xf4};
	Color		*g;

	p.y = -1;
	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	env->color = (Color){0xf4, 0x42, 0x53};
	Color tmp = env->color;
	while (env->w_size.y > ++(p.y) && (p.x = -1))
	{
		g = sdl_clrs_gradient(env->color, c1, env->w_size.x);
		if (env->w_size.y / 2 > p.y)
			env->color = *sdl_clrs_bright_inc(&env->color, c1, INC);
		else if (!sdl_clrs_equal(env->color, tmp))
			env->color = *sdl_clrs_bright_dec(&env->color, c1, INC);
		while (env->w_size.x > ++(p.x))
			sdl_pixelput(env->sdl->wsurf, p.x, p.y, g[p.x]);
		free(g);
	}
	SDL_UpdateWindowSurface(env->sdl->w);
}
