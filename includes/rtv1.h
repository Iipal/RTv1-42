/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/18 10:07:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libftsdl.h"
# include "rtv1_errno.h"
# include "rtv1_structs.h"
# include "rtv1_macroses.h"

extern bool		rt_read_scene(Environment *env, string scene_file);
extern bool		rt_valid_readed_data(Scene *s);

extern bool		rt_scam(Camera *cam, string s);
extern bool		rt_slight(Light *l, string s);

extern bool		rt_ssphere(Object *obj, string s);
extern bool		rt_scone(Object *obj, string s);
extern bool		rt_splane(Object *obj, string s);
extern bool		rt_scylinder(Object *obj, string s);

extern Vector	rt_inter_sphere(const Vector a,
								const Vector b,
								const void *restrict obj_ptr);
extern Vector	rt_inter_cone(const Vector a,
								const Vector b,
								const void *restrict obj_ptr);
extern Vector	rt_inter_plane(const Vector a,
								const Vector b,
								const void *restrict obj_ptr);
extern Vector	rt_inter_cylinder(const Vector a,
								const Vector b,
								const void *restrict obj_ptr);

extern Vector	rt_normal_sphere(const Vector p,
								const Vector d,
								const Camera *restrict cam,
								const void *restrict obj_ptr);
extern Vector	rt_normal_cone(const Vector p,
								const Vector d,
								const Camera *restrict cam,
								const void *restrict obj_ptr);
extern Vector	rt_normal_plane(const Vector p,
								const Vector d,
								const Camera *restrict cam,
								const void *restrict obj_ptr);
extern Vector	rt_normal_cylinder(const Vector p,
								const Vector d,
								const Camera *restrict cam,
								const void *restrict obj_ptr);

extern bool		rt_init(Environment *env);

extern bool		rt_flags_parser(Flags *f, strtab av, const size_t ac);
extern bool		rt_fhelp(Flags *f, strtab av, const size_t ac, size_t *av_i);
extern bool		rt_fvps(Flags *f, strtab av, const size_t ac, size_t *av_i);
extern bool		rt_fsb(Flags *f, strtab av, const size_t ac, size_t *av_i);
extern bool		rt_fftc(Flags *f, strtab av, const size_t ac, size_t *av_i);

extern void		rt_camera_speed_movements(double_t *cam_speed,
					const bool is_speed_up, const bool is_speed_down);

extern void		rt_sdl_keys_press(Environment *env);
extern void		rt_sdl_keys_release(Environment *env);
extern void		rt_sdl_keys_events(Environment *env);
extern void		rt_sdl_keys_events_objs_debug(Environment *env);
extern void		rt_sdl_keys_events_light_debug(Environment *env);

extern void		rt_rendering(Environment *env);
extern void		rt_render_loop(Environment *env);
extern void		rt_render_fps_counter(Environment *env);

extern Color	rt_raytracing(Environment *env, const Vector d);

extern Color	rt_calculate_light(Environment *env, t_clhelp *h,
					const Object *obj, const Vector d);

extern Object	*rt_closest_inter(const Vector o,
					const Vector d, Environment *env);

extern void		rt_fps(Fps *fps, double_t cam_speed);

extern void		rt_free(Environment **env);

extern bool		u_inrangev(const Vector v,
					const bool check_min, const bool check_max);
extern double_t	u_inranged(const double_t v,
					const bool check_min, const bool check_max);
extern Vector	u_inrange_dir_max(Vector dir);
extern Vector	u_inrange_dir_min(Vector dir);

#endif
