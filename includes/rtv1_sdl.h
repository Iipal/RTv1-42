/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_sdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:00:05 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/08 23:28:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_SDL_H
# define RTV1_SDL_H

# include "rtv1_structs.h"

/*
** rt_sdl_fake_render_loop if RTv1 was launch without -dbg flag.
*/
void	rt_sdl_fake_render_loop(Environment *restrict const env);
void	rt_sdl_render_loop(Environment *restrict const env);

void	rt_sdl_keys_press(SDL_Keycode const key);
void	rt_sdl_keys_press_switcher_mode(SDL_Keycode const key);
void	rt_sdl_keys_press_add_settings(SDL_Keycode const key);
void	rt_sdl_keys_release(SDL_Keycode const key);

void	rt_sdl_keys_events(Environment *restrict const env);
void	rt_sdl_keys_events_objs_debug(Object *restrict const o,
									Fps const *restrict const fps,
									size_t const in_scene_objects);
void	rt_sdl_keys_events_lights_debug(Light *restrict const l,
									Fps const *restrict const fps,
									size_t const in_scene_lights);


#endif
