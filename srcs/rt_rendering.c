/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 20:16:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_rendering(Enviroment *env)
{
	point	p;

	p.y = -1;
	while (env->win_size.y > ++(p.y) && (p.x = -1))
		while (env->win_size.x > ++(p.x))
			sdl_pixelput(env->sdl->win_surf, p.x, p.y, 0xff);
	SDL_UpdateWindowSurface(env->sdl->win);
}
