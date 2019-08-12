/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_render_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:20:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/12 19:58:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_sdl_render_loop(Environment *restrict const env)
{
	bool	quit;

	quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&env->sdl->e) > 0)
			if (SDL_QUIT == env->sdl->e.type)
				quit = true;
			else if (SDL_KEYDOWN == env->sdl->e.type)
			{
				if (SDLK_ESCAPE == env->sdl->e.key.keysym.sym)
					quit = true;
				else
				{
					rt_sdl_keys_press(env->sdl->e.key.keysym.sym);
					rt_sdl_keys_press_switcher_mode(env->sdl->e.key.keysym.sym);
					rt_sdl_keys_press_add_settings(env->sdl->e.key.keysym.sym);
				}
			}
			else if (env->sdl->e.type == SDL_KEYUP)
				rt_sdl_keys_release(env->sdl->e.key.keysym.sym);
		rt_sdl_keys_events(env);
		rt_rendering(env);
		SDL_UpdateWindowSurface(env->sdl->w);
		rt_fps(&env->fps, env->cam_speed);
	}
}
