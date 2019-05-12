/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/12 13:35:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libftsdl.h"
# include "rtv1_errno.h"
# include "rtv1_structs.h"
# include "rtv1_macroses.h"

bool		rt_scam(Scene *sc, string s, size_t *o);
bool		rt_slight(Scene *sc, string s, size_t *o);
bool		rt_ssphere(Scene *sc, string s, size_t *o);
bool		rt_read_scene(Environment *env, string scene_file);

bool		rt_init(Environment *env);

bool		u_inrange(const t_vec v,
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

void		rt_rendering(Environment *env);
void		rt_render_loop(Environment *env);
void		rt_render_fps_counter(Environment *env);

void		rt_raytracing(Environment *env);

Color		rt_calculate_light(Environment *env, Object *obj, t_vec d);

Object		*rt_closest_inter(const t_vec o,
							const t_vec d,
							Environment *env,
							bool is_shadow);

void		rt_fps(Fps *fps, double_t cam_speed);

void		rt_free(Environment **env);

#endif
