/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/17 10:21:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "parson.h"
# include "libftsdl.h"
# include "rtv1_errno.h"
# include "rtv1_flags.h"
# include "rtv1_structs.h"
# include "rtv1_macroses.h"

/*
** Validate executable path and scene file name.
*/
extern bool		rt_valid_exe_path(char *const path);
extern bool		rt_valid_filename(char *const file);

/*
** Parse and validate scene file:
*/
# include "rtv1_scene_parse.h"

/*
** Initialization and pre-calculating:
*/
extern void		rt_init_flags(Flags *restrict const flags);
extern bool		rt_init_textures(Object *restrict const objs,
							const size_t ins_objs,
							const SDL_PixelFormat *format);
bool			rt_precalc_d(Environment *restrict const env);

/*
** SDL render loop, keypresses and keybinds mode switcher:
*/
# include "rtv1_sdl.h"

/*
** Rendering adn other rendering stuff:
*/
void			rt_rendering(Environment *restrict const env);

Color			rt_anti_aliasing(Environment *restrict const env,
							const size_t aa, __v4df d_calc);

extern void		rt_camera_speed_movements(double_t *restrict const cam_speed,
							const bool is_speed_up, const bool is_speed_down);

void			rt_randomize_lights_intense(Light *restrict const lights,
							const size_t ins_lights,
							const float time);

extern void		rt_fps(Fps *restrict const fps, double_t cam_speed);
extern void		rt_render_fps_counter(Environment *const env);

/*
** Ray Tracing:
*/
# include "rtv1_rt.h"

/*
** Free all malloced memory:
*/
extern void		rt_free(Environment *restrict *env);

/*
** Ohter utilites funcs:
**  Used only when validating readed data for convert direction\rotate
**   from 365 degress to 360;
*/
__v4df			u_inrange_dir_max(__v4df dir);
__v4df			u_inrange_dir_min(__v4df dir);

#endif
