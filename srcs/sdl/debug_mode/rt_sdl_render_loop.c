/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_render_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:20:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/11 11:59:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					rt_sdl_render_loop(Environment *restrict const env)
{
	Environment	**env_dups;
	bool		quit;
	SDL_Keycode	key;
	int			is_update;
	int			temp;

	quit = false;
	env_dups = rt_prepare_threading(env);
	rt_render_threads_create(env_dups);
	while (!quit) {
		is_update = 0;
		while (SDL_PollEvent(&env->sdl->e) > 0) {
			key = env->sdl->e.key.keysym.sym;
			if (SDL_QUIT == env->sdl->e.type)
				quit = true;
			else if (SDL_KEYDOWN == env->sdl->e.type) {
				if (SDLK_ESCAPE == key)
					quit = true;
				else {
					is_update = rt_sdl_keys_press(key);
					temp = rt_sdl_keys_press_switcher_mode(key);
					if (!is_update && temp)
						is_update = temp;
					temp = rt_sdl_keys_press_add_settings(key);
					if (!is_update && temp)
						is_update = temp;
				}
			}
			else if (env->sdl->e.type == SDL_KEYUP)
				is_update = rt_sdl_keys_release(key);
		}
		if (is_update) {
			SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
			rt_sdl_keys_events(env);
			rt_update_threading(env_dups, env);
		}
		SDL_UpdateWindowSurface(env->sdl->w);
		rt_fps(&env->fps, env->cam_speed);
		// if (IS_BIT(g_isr_flags, ISR_RENDER_FPS))
			// rt_render_fps_counter(&env->flags.fps_text_color, &env->fps.time,
				// env->sdl, env->flags.fps_refresh_timer, env->frh);
		if (IS_BIT(g_flags, F_BIT_RLI) && !IS_BIT(g_flags, F_BIT_NCL))
			rt_randomize_lights_intense(env->scene.lights,
				env->scene.ins_lights, env->fps.time.res);
	}
	rt_free_threading(env_dups);
}
