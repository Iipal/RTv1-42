/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/17 13:30:42 by tmaluh           ###   ########.fr       */
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

Vec		*u_cp_vec(Vec *v, double x, double y, double z);
Vec		*u_cp_vvec(Vec *dst, Vec src);

void	rt_rendering(Environment *env);

void	rt_free(Environment **env);

#endif
