/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/08 15:13:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libftsdl.h"
# include "rtv1_errno.h"
# include "rtv1_structs.h"
# include "rtv1_macroses.h"
# include <math.h>

# define FNSCP typedef bool (*fns_parse)(Scene*, string, int32_t*);

FNSCP;

bool	rt_scam(Scene *sc, string s, int32_t *o);
bool	rt_slight(Scene *sc, string s, int32_t *o);
bool	rt_ssphere(Scene *sc, string s, int32_t *o);
bool	rt_read_scene(Environment *env, string scene_file);

bool	rt_intersection(Environment *env, Vec d, fDot *t, int32_t i);

bool	rt_init(Environment *env);

Vec		u_sub_vec(Vec a, Vec b);

bool	u_inrange(Vec v, bool check_min, bool check_max);
double	u_inrangev(double v, bool check_min, bool check_max);

void	rt_camera_speed(double *cam_s, bool is_speed_up, bool is_speed_down);

void	rt_sdl_keys_press(Environment *env);
void	rt_sdl_keys_release(Environment *env);
void	rt_sdl_keys_events(Environment *env);

void	rt_rendering(Environment *env);
void	rt_render_loop(Environment *env);
void	rt_render_fps_counter(Environment *env);

void	rt_raytracing(Environment *env);

void	rt_fps(Fps *fps, double cam_speed);

void	rt_free(Environment **env);

#endif
