/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_render_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:20:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/09 00:41:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			rt_render_loop(Environment *env)
{
	bool	quit;

	quit = false;
	while (!quit)
	{
		rt_camera_speed(&env->cam_speed,
			env->isr.is_cam_speedup, env->isr.is_cam_speeddown);
		while (SDL_PollEvent(&env->sdl->e) > 0)
			if (env->sdl->e.type == SDL_QUIT)
				quit = true;
			else if (env->sdl->e.type == SDL_KEYDOWN)
			{
				if (SEKEY == SDLK_ESCAPE)
					quit = true;
				else
					rt_sdl_keys_press(env);
			}
			else if (env->sdl->e.type == SDL_KEYUP)
				rt_sdl_keys_release(env);
		rt_sdl_keys_events(env);
		rt_rendering(env);
		rt_fps(&env->fps, env->cam_speed);
	}
}
