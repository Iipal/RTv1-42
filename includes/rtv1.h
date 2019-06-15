/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/15 16:44:17 by tmaluh           ###   ########.fr       */
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
** Read and validate scene file:
*/
bool			rt_parse_scene(Environment *env,
							const char *const scene_file);

bool			rt_parse_cam(Camera *const camera,
							JSON_Object *const root_obj);
bool			rt_parse_lights(Scene *const scene,
							JSON_Object *root_obj);
bool			rt_parse_objects(Scene *const scene,
							JSON_Object *root_obj);

typedef bool (*t_fn_lght)(const JSON_Object *const, Light *const, const size_t);
bool			rt_parse_point_light(const JSON_Object *const light_obj,
							Light *const l, const size_t curr_light);
bool			rt_parse_dir_light(const JSON_Object *const light_obj,
							Light *const l, const size_t curr_light);
typedef bool (*t_fn_obj)(const JSON_Object *const, Object *const, const size_t);
bool			rt_parse_sphere(const JSON_Object *const object_obj,
							Object *const obj, const size_t curr_obj);
bool			rt_parse_plane(const JSON_Object *const object_obj,
							Object *const obj, const size_t curr_obj);

bool			rt_parse_arr_to_vec(const JSON_Array *const arr,
							__v4df *const dst,
							const char *const obj_name,
							const size_t parsing_obj_counter);
bool			rt_parse_color(string hex_str,
							Color *const dst,
							const size_t parsing_obj_counter);

extern bool		rt_read_vec(string *const s, __v4df *const v);

bool			rt_parsed_validation(Scene *restrict const s);

extern bool		rt_init_env(Environment *restrict env);
extern bool		rt_init_textures(Object *restrict const objs,
							const size_t ins_objs,
							const SDL_PixelFormat *format);
bool			rt_precalc_d(Environment *restrict const env);

/*
** SDL render loop, keypresses and keybinds mode switcher:
**
** rt_sdl_fake_render_loop if RTv1 was launch without -dbg flag.
*/
void			rt_sdl_fake_render_loop(Environment *restrict const env);

void			rt_render_loop(Environment *restrict const env);
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

extern void		rt_camera_speed_movements(double_t *restrict const cam_speed,
							const bool is_speed_up, const bool is_speed_down);
extern __v4df	rt_camera_rotate(__v4df d, const __v4df dir);

void			rt_randomize_lights_intense(Light *restrict const lights,
							const size_t ins_lights,
							const float time);

/*
** Ray Tracing:
*/
void			rt_rendering(Environment *restrict const env);
Color			rt_anti_aliasing(Environment *restrict const env,
							const size_t aa, __v4df d_calc);

extern Color	rt_raytracing(Environment *restrict const env, __v4df d);

/*
** Objects intersection calc:
*/
Object			*rt_closest_inter(const __v4df o, const __v4df d,
							Environment *restrict const env);
extern __v4df	rt_inter_sphere(const __v4df x, const __v4df d,
							void const *restrict const obj_ptr);
extern __v4df	rt_inter_cone(const __v4df x, const __v4df d,
							void const *restrict const obj_ptr);
extern __v4df	rt_inter_plane(const __v4df x, const __v4df d,
							void const *restrict const obj_ptr);
extern __v4df	rt_inter_cylinder(const __v4df x, const __v4df d,
							void const *restrict const obj_ptr);

/*
** Objects nomrals calcs:
*/
extern __v4df	rt_normal_sphere(const __v4df p, const __v4df d,
							Camera const *restrict const cam,
							void const *restrict const obj_ptr);
extern __v4df	rt_normal_cone(const __v4df p, const __v4df d,
							Camera const *restrict const cam,
							void const *restrict const obj_ptr);
extern __v4df	rt_normal_plane(const __v4df p, const __v4df d,
							Camera const *restrict const cam,
							void const *restrict const obj_ptr);
extern __v4df	rt_normal_cylinder(const __v4df p, const __v4df d,
							Camera const *restrict const cam,
							void const *restrict const obj_ptr);

/*
** Objects uv-mapping calcs:
*/
extern Uint32	rt_uv_sphere(SDL_Surface *restrict const tex, const __v4df n);
extern Uint32	rt_uv_cone(SDL_Surface *restrict const tex, const __v4df n);
extern Uint32	rt_uv_plane(SDL_Surface *restrict const tex, const __v4df n);
extern Uint32	rt_uv_cylinder(SDL_Surface *restrict const tex, const __v4df n);

/*
** Calc light:
*/
Color			rt_calc_light(Environment *restrict const env,
							t_clhelp *restrict const h,
							const __v4df d);

/*
** FPS counter and drawing this counter:
*/
extern void		rt_fps(Fps *restrict const fps, double_t cam_speed);
extern void		rt_render_fps_counter(Environment *const env);

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
