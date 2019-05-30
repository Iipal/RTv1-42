/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/30 12:56:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libftsdl.h"
# include "rtv1_errno.h"
# include "rtv1_structs.h"
# include "rtv1_macroses.h"

/*
** Read and validate scene file:
*/
bool			rt_read_scene(Environment *restrict const env,
							const char *const scene_file);

extern bool		rt_scam(Camera *restrict const cam, char *restrict s);
extern bool		rt_slight(Light *restrict const l, char *restrict s);

typedef bool	(*t_fn_sparse)(Object *restrict const, char *restrict);
extern bool		rt_ssphere(Object *restrict const obj, char *restrict s);
extern bool		rt_scone(Object *restrict const obj, char *restrict s);
extern bool		rt_splane(Object *restrict const obj, char *restrict s);
extern bool		rt_scylinder(Object *restrict const obj, char *restrict s);

bool			rt_valid_readed_data(Scene *restrict const s);

extern bool		rt_init(Environment *restrict env);

/*
**	Flags parsing:
*/
bool			rt_flags_parser(Flags *const f, strtab av, const size_t ac);

typedef bool	(*t_fn_fparse)(Flags *, char**, const size_t, size_t *const);
extern bool		rt_fhelp(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fvps(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fsb(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fftc(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_ffrt(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fdbg(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fncl(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_ftex(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fpu(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);

/*
** SDL render loop, keypresses and keybinds mode switcher:
*/
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
extern Vector	rt_camera_rotate(Vector d, const Vector dir);

/*
** Ray Tracing:
*/
void			rt_rendering(Environment *restrict const env);

extern Color	rt_raytracing(Environment *restrict const env, Vector d);

/*
** Objects intersection calc:
*/
Object			*rt_closest_inter(const Vector o, const Vector d,
								Environment *restrict const env);
extern Vector	rt_inter_sphere(const Vector x, const Vector d,
								void const *restrict const obj_ptr);
extern Vector	rt_inter_cone(const Vector x, const Vector d,
								void const *restrict const obj_ptr);
extern Vector	rt_inter_plane(const Vector x, const Vector d,
								void const *restrict const obj_ptr);
extern Vector	rt_inter_cylinder(const Vector x, const Vector d,
								void const *restrict const obj_ptr);

/*
** Objects nomrals calcs:
*/
extern Vector	rt_normal_sphere(const Vector p, const Vector d,
								Camera const *restrict const cam,
								void const *restrict const obj_ptr);
extern Vector	rt_normal_cone(const Vector p, const Vector d,
								Camera const *restrict const cam,
								void const *restrict const obj_ptr);
extern Vector	rt_normal_plane(const Vector p, const Vector d,
								Camera const *restrict const cam,
								void const *restrict const obj_ptr);
extern Vector	rt_normal_cylinder(const Vector p, const Vector d,
								Camera const *restrict const cam,
								void const *restrict const obj_ptr);

/*
** Objects uv-mapping calcs:
*/
extern Color	rt_uv_sphere(SDL_Surface *restrict const tex, const Vector n);
extern Color	rt_uv_cone(SDL_Surface *restrict const tex, const Vector n);
extern Color	rt_uv_plane(SDL_Surface *restrict const tex, const Vector n);
extern Color	rt_uv_cylinder(SDL_Surface *restrict const tex, const Vector n);

/*
** Calc light:
*/
Color			rt_calc_light(Environment *restrict const env,
					t_clhelp *restrict const h,
					const Vector d);

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
** Ohter util funcs:
**  Used only when validating readed data for convert direction\rotate
**   from 365 degress to 360;
*/
Vector			u_inrange_dir_max(Vector dir);
Vector			u_inrange_dir_min(Vector dir);

#endif
