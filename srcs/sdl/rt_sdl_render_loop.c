/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_render_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:20:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/28 22:55:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			rt_render_loop(Environment *env)
{
	bool	exit_;

	exit_ = false;
	while (!exit_)
	{
		rt_camera_speed(&env->cam_speed,
			env->isr.is_cam_speedup, env->isr.is_cam_speeddown);
		while (SDL_PollEvent(&env->sdl->e) > 0)
			if (env->sdl->e.type == SDL_QUIT)
				exit_ = true;
			else if (env->sdl->e.type == SDL_KEYDOWN)
			{
				if (SEKEY == SDLK_ESCAPE)
					exit_ = true;
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
