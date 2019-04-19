/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/19 19:23:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libftsdl.h"
# include "rtv1_errno.h"
# include "rtv1_structs.h"
# include "rtv1_macroses.h"
# include <math.h>

# define FNSCP typedef bool (*fn_scene_parse)(Scene*, string);

FNSCP;

bool	rt_scam(Scene *sc, string s);
bool	rt_slight(Scene *sc, string s);
bool	rt_ssphere(Scene *sc, string s);

bool	rt_read_scene(Environment *env, string scene_file);
bool	rt_init(Environment *env);

bool	u_inrange(Vec v, bool check_min, bool check_max);

Vec		*u_cp_vec(Vec *v, double x, double y, double z);
Vec		*u_cp_vvec(Vec *dst, Vec src);
Vec		u_sub_vec(Vec a, Vec b);
float	u_mul_vec(Vec a, Vec b);

void	rt_sdl_keys_press(Environment *env);
void	rt_sdl_keys_release(Environment *env);
void	rt_sdl_keys_events(Environment *env);

void	rt_render_loop(Environment *env);
void	rt_rendering(Environment *env);
void	rt_render_fps_counter(Environment *env);

void	rt_raytracing(Environment *env);

void	rt_fps(Fps *fps);

void	rt_free(Environment **env);

#endif
