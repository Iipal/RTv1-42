/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/16 16:15:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libftsdl.h"
# include "rtv1_errno.h"
# include "rtv1_structs.h"
# include "rtv1_macroses.h"
# include <math.h>

typedef bool (*fn_scene_parse)(Environment*, string);

bool	rt_read_scene(Environment *env, string scene_file);
bool	rt_init(Environment *env);

Vec		*u_cp_vec(Vec *v, double x, double y, double z);
Vec		*u_cp_vvec(Vec *dst, Vec src);
Ray		*u_cp_ray(Ray *r, Vec origin, Vec direction);

void	rt_rendering(Environment *env);

void	rt_free(Environment **env);

#endif
