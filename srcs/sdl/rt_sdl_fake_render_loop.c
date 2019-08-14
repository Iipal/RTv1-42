/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_fake_render_loop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:39:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/14 22:01:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_sdl_fake_render_loop(Environment *restrict const env)
{
	bool	quit;

	quit = false;
	rt_rendering(env);
	while (!quit)
	{
		while (SDL_PollEvent(&env->sdl->e) > 0)
			if (SDL_QUIT == env->sdl->e.type)
				quit = true;
			else if (SDL_KEYDOWN == env->sdl->e.type
				&& SDLK_ESCAPE == env->sdl->e.key.keysym.sym)
				quit = true;
		SDL_UpdateWindowSurface(env->sdl->w);
	}
}
