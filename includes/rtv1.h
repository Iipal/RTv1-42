/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/12 13:11:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>

# include "parson.h"

# include "wu_algo.h"

# include "libftsdl.h"

# include "rtv1_errno.h"
# include "rtv1_flags.h"
# include "rtv1_isr_flags.h"
# include "rtv1_structs.h"
# include "rtv1_macroses.h"
# include "rtv1_scene_parse.h"
# include "rtv1_sdl.h"
# include "rtv1_rt.h"

/*
** Validate executable path and scene file name.
*/
bool			rt_valid_exe_path(char const *path);
bool			rt_valid_filename(char const *file);


/*
** Initialization and pre-calculating:
*/
bool			rt_main_env_init(Environment *const env);
bool			rt_init_textures(Object *restrict const objs,
					size_t const ins_objs,
					SDL_PixelFormat const *format);
bool			rt_precalc_d(Environment *restrict const env);
FpsRenderHelper	*rt_init_fps_render_helper(void);

/*
** Rendering and other rendering stuff:
*/
void		rt_rendering(Environment *restrict const env);

Color		rt_anti_aliasing(Environment *restrict const env,
				size_t const aa,
				__v4df d_calc);

void		rt_camera_speed_movements(double_t *restrict const cam_speed);

void		rt_randomize_lights_intense(Light *restrict const lights,
				size_t const ins_lights,
				float const time);

void		rt_fps(Fps *restrict const fps, double_t const cam_speed);
void		rt_render_fps_counter(Color const *text_clr,
				Time *const fps,
				Sdl const *const sdl,
				double_t const frt,
				FpsRenderHelper *const frh);

/*
** Free all malloced memory:
*/
void		rt_free(Environment *restrict *env);

/*
** Ohter utilites funcs:
**  Used only when validating read data for convert direction\rotate
**   from 365 degrees to 5;
*/
__v4df		u_inrange_dir_max(__v4df dir);
__v4df		u_inrange_dir_min(__v4df dir);

#endif
