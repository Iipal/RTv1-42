/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_sdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:00:05 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/15 18:02:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_SDL_H
# define RTV1_SDL_H

# include "rtv1_structs.h"

/*
** rt_sdl_fake_render_loop if RTv1 was launch without -dbg flag.
*/
void			rt_sdl_fake_render_loop(Environment *restrict const env);
void			rt_sdl_render_loop(Environment *restrict const env);

extern void		rt_sdl_keys_press(Isr *restrict const isr,
							const SDL_Keycode key);
extern void		rt_sdl_keys_press_switcher_mode(Isr *restrict const isr,
							const SDL_Keycode key);
extern void		rt_sdl_keys_press_add_settings(Environment *restrict const env,
							const SDL_Keycode key);
extern void		rt_sdl_keys_release(Isr *restrict const isr,
							const SDL_Keycode key);

extern void		rt_sdl_keys_events(Environment *restrict const env);
void			rt_sdl_keys_events_objs_debug(Object *restrict const o,
											const Fps *restrict const fps,
											const Isr *restrict const isr,
											const size_t in_scene_objects);
void			rt_sdl_keys_events_lights_debug(Light *restrict const l,
											const Fps *restrict const fps,
											const Isr *restrict const isr,
											const size_t in_scene_lights);


#endif
