/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/09 13:45:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libftsdl.h"
# include "rtv1_errno.h"
# include "rtv1_structs.h"
# include "rtv1_macroses.h"

bool		rt_scam(Scene *sc, string s, int32_t *o);
bool		rt_slight(Scene *sc, string s, int32_t *o);
bool		rt_ssphere(Scene *sc, string s, int32_t *o);
bool		rt_read_scene(Environment *env, string scene_file);

bool		rt_init(Environment *env);

bool		u_inrange(t_vec v, bool check_min, bool check_max);
double_t	u_inrangev(double_t v, bool check_min, bool check_max);

void		rt_camera_speed_movements(double_t *cam_speed,
						bool is_speed_up, bool is_speed_down);

void		rt_sdl_keys_press(Environment *env);
void		rt_sdl_keys_release(Environment *env);
void		rt_sdl_keys_events(Environment *env);

void		rt_rendering(Environment *env);
void		rt_render_loop(Environment *env);
void		rt_render_fps_counter(Environment *env);

void		rt_raytracing(Environment *env);

Color		rt_calculate_light(Environment *env, int32_t i, t_vec d);
bool		rt_intersection(Environment *env, t_vec d, fDot *t, int32_t i);

void		rt_fps(Fps *fps, double_t cam_speed);

void		rt_free(Environment **env);

#endif
