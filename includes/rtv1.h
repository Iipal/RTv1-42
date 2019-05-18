/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/19 00:32:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libftsdl.h"
# include "rtv1_errno.h"
# include "rtv1_structs.h"
# include "rtv1_macroses.h"

extern bool		rt_read_scene(Environment *restrict env,
							char const *restrict const scene_file);

extern bool		rt_scam(Camera *restrict const cam, string s);
extern bool		rt_slight(Light *restrict const l, string s);

typedef bool	(*t_fn_sparse)(Object *restrict const, char*);
extern bool		rt_ssphere(Object *restrict const obj, string s);
extern bool		rt_scone(Object *restrict const obj, string s);
extern bool		rt_splane(Object *restrict const obj, string s);
extern bool		rt_scylinder(Object *restrict const obj, string s);

extern bool		rt_valid_readed_data(Scene *restrict const s);

extern bool		rt_init(Environment *restrict env);

extern bool		rt_flags_parser(Flags *restrict const f, strtab av,
								const size_t ac);

typedef bool	(*t_fn_fparse)(Flags *restrict, char**,
							const size_t, size_t *restrict const);
extern bool		rt_fhelp(Flags *restrict const f, strtab av,
					const size_t ac, size_t *restrict const av_i);
extern bool		rt_fvps(Flags *restrict const f, strtab av,
					const size_t ac, size_t *restrict const av_i);
extern bool		rt_fsb(Flags *restrict const f, strtab av,
					const size_t ac, size_t *restrict const av_i);
extern bool		rt_fftc(Flags *restrict const f, strtab av,
					const size_t ac, size_t *restrict const av_i);

extern void		rt_camera_speed_movements(double_t *cam_speed,
					const bool is_speed_up, const bool is_speed_down);

extern void		rt_sdl_keys_press(Isr *restrict const isr,
					const SDL_Keycode key);
extern void		rt_sdl_keys_release(Isr *restrict const isr,
					const SDL_Keycode key);
extern void		rt_sdl_keys_events(Environment *restrict env);

extern void		rt_sdl_keys_events_objs_debug(Object *restrict o,
											Fps const *restrict fps,
											Isr const *restrict isr,
											const size_t in_scene_objects);
extern void		rt_sdl_keys_events_lights_debug(Light *restrict l,
											Fps const *restrict fps,
											Isr const *restrict isr,
											const size_t in_scene_lights);

extern void		rt_rendering(Environment *restrict env);
extern void		rt_render_loop(Environment *restrict env);
extern void		rt_render_fps_counter(Environment *restrict env);

extern Color	rt_raytracing(Environment *restrict env, const Vector d);

extern Vector	rt_inter_sphere(const Vector a,
								const Vector b,
								void const *restrict const obj_ptr);
extern Vector	rt_inter_cone(const Vector a,
								const Vector b,
								void const *restrict const obj_ptr);
extern Vector	rt_inter_plane(const Vector a,
								const Vector b,
								void const *restrict const obj_ptr);
extern Vector	rt_inter_cylinder(const Vector a,
								const Vector b,
								void const *restrict const obj_ptr);

extern Vector	rt_normal_sphere(const Vector p,
								const Vector d,
								Camera const *restrict const cam,
								void const *restrict const obj_ptr);
extern Vector	rt_normal_cone(const Vector p,
								const Vector d,
								Camera const *restrict const cam,
								void const *restrict const obj_ptr);
extern Vector	rt_normal_plane(const Vector p,
								const Vector d,
								Camera const *restrict const cam,
								void const *restrict const obj_ptr);
extern Vector	rt_normal_cylinder(const Vector p,
								const Vector d,
								Camera const *restrict const cam,
								void const *restrict const obj_ptr);

extern Color	rt_calculate_light(Environment *restrict env,
					t_clhelp *restrict const h,
					Object const *restrict const obj,
					const Vector d);

extern Object	*rt_closest_inter(const Vector o,
					const Vector d, Environment *restrict env);

extern void		rt_fps(Fps *restrict const fps, double_t cam_speed);

extern void		rt_free(Environment * restrict* env);

extern Vector	u_inrange_dir_max(Vector dir);
extern Vector	u_inrange_dir_min(Vector dir);

#endif
