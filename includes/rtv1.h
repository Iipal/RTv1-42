/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/19 15:34:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libftsdl.h"
# include "rtv1_errno.h"
# include "rtv1_structs.h"
# include "rtv1_macroses.h"

bool			rt_read_scene(Environment *env,
							char const *const scene_file);

extern bool		rt_scam(Camera *const cam, string s);
extern bool		rt_slight(Light *const l, string s);

typedef bool	(*t_fn_sparse)(Object *const, char*);
extern bool		rt_ssphere(Object *const obj, string s);
extern bool		rt_scone(Object *const obj, string s);
extern bool		rt_splane(Object *const obj, string s);
extern bool		rt_scylinder(Object *const obj, string s);

bool			rt_valid_readed_data(Scene *const s);

extern bool		rt_init(Environment *env);

bool			rt_flags_parser(Flags *const f, strtab av, const size_t ac);

typedef bool	(*t_fn_fparse)(Flags *, char**,
							const size_t, size_t *const);
extern bool		rt_fhelp(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fvps(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fsb(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fftc(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);

extern void		rt_camera_speed_movements(double_t *const cam_speed,
					const bool is_speed_up, const bool is_speed_down);

extern void		rt_sdl_keys_press(Isr *const isr,
					const SDL_Keycode key);
extern void		rt_sdl_keys_release(Isr *const isr,
					const SDL_Keycode key);
extern void		rt_sdl_keys_events(Environment *env);

void			rt_sdl_keys_events_objs_debug(Object *o,
										const Fps *const fps,
										const Isr *const isr,
										const size_t in_scene_objects);
void			rt_sdl_keys_events_lights_debug(Light *l,
										const Fps *const fps,
										const Isr *const isr,
										const size_t in_scene_lights);

void			rt_rendering(Environment *const env);
void			rt_render_loop(Environment *const env);
extern void		rt_render_fps_counter(Environment *const env);

extern Color	rt_raytracing(Environment *const env, const Vector d);

extern Vector	rt_inter_sphere(const Vector a,
								const Vector b,
								void const *const obj_ptr);
extern Vector	rt_inter_cone(const Vector a,
								const Vector b,
								void const *const obj_ptr);
extern Vector	rt_inter_plane(const Vector a,
								const Vector b,
								void const *const obj_ptr);
extern Vector	rt_inter_cylinder(const Vector a,
								const Vector b,
								void const *const obj_ptr);

extern Vector	rt_normal_sphere(const Vector p,
								const Vector d,
								Camera const *const cam,
								void const *const obj_ptr);
extern Vector	rt_normal_cone(const Vector p,
								const Vector d,
								Camera const *const cam,
								void const *const obj_ptr);
extern Vector	rt_normal_plane(const Vector p,
								const Vector d,
								Camera const *const cam,
								void const *const obj_ptr);
extern Vector	rt_normal_cylinder(const Vector p,
								const Vector d,
								Camera const *const cam,
								void const *const obj_ptr);

Color			rt_calculate_light(Environment *env,
								t_clhelp *const h,
								Object const *const obj,
								const Vector d);

Object			*rt_closest_inter(const Vector o,
								const Vector d,
								Environment *const env);

extern void		rt_fps(Fps *const fps, double_t cam_speed);

extern void		rt_free(Environment **env);

Vector			u_inrange_dir_max(Vector dir);
Vector			u_inrange_dir_min(Vector dir);

#endif
