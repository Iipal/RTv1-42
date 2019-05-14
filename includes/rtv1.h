/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 20:00:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libftsdl.h"
# include "rtv1_errno.h"
# include "rtv1_structs.h"
# include "rtv1_macroses.h"

bool		rt_read_scene(Environment *env, string scene_file);

bool		rt_scam(Camera *cam, string s);
bool		rt_slight(Light *l, string s);

bool		rt_ssphere(Object *obj, string s);
bool		rt_splane(Object *obj, string s);
bool		rt_scylinder(Object *obj, string s);

bool		rt_init(Environment *env);

bool		rt_flags_parser(Flags *f, strtab av, const size_t ac);
bool		rt_fhelp(Flags *f, strtab av, const size_t ac, size_t *av_i);
bool		rt_fvps(Flags *f, strtab av, const size_t ac, size_t *av_i);
bool		rt_fsb(Flags *f, strtab av, const size_t ac, size_t *av_i);

bool		u_inrange(const Vector v,
					const bool check_min,
					const bool check_max);
double_t	u_inrangev(const double_t v,
					const bool check_min,
					const bool check_max);

void		rt_camera_speed_movements(double_t *cam_speed,
									bool is_speed_up,
									bool is_speed_down);

void		rt_sdl_keys_press(Environment *env);
void		rt_sdl_keys_release(Environment *env);
void		rt_sdl_keys_events(Environment *env);
void		rt_sdl_keys_events_light_debug(Environment *env);

void		rt_rendering(Environment *env);
void		rt_render_loop(Environment *env);
void		rt_render_fps_counter(Environment *env);

void		rt_raytracing(Environment *env, Dot i);

Color		rt_calculate_light(Environment *env, t_clhelp *h,
						const Object *obj,
						const Vector d);

Object		*rt_closest_inter(const Vector o,
							const Vector d,
							Environment *env);

void		rt_fps(Fps *fps, double_t cam_speed);

void		rt_free(Environment **env);

#endif
