/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_fake_render_loop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:39:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 22:19:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_sdl_fake_render_loop(Environment *restrict const env)
{
	Environment	**env_dups;
	bool	quit;

	quit = false;
	env_dups = rt_prepare_threading(env);
	rt_render_threds_create(env_dups);
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
	rt_free_threading(env_dups);
}
