/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:02:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 22:27:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_RT_H
# define RTV1_RT_H

# include "rtv1_structs.h"

Color	rt_raytracing(void *restrict const arg, t_v4df d) NON_NULL((1));

t_v4df	rt_camera_rotate(t_v4df d, t_v4df const dir);

/*
** Objects intersection calc:
*/
Object	*rt_intersection(t_v4df const o, t_v4df const d,
			Scene *restrict const scene) NON_NULL((3));
t_v4df	rt_inter_sphere(t_v4df const x, t_v4df const d,
			void const *restrict const obj_ptr) NON_NULL((3));
t_v4df	rt_inter_cone(t_v4df const x, t_v4df const d,
			void const *restrict const obj_ptr) NON_NULL((3));
t_v4df	rt_inter_cylinder(t_v4df const x, t_v4df const d,
			void const *restrict const obj_ptr) NON_NULL((3));

/*
** Objects normals calcs:
*/
t_v4df	rt_normal_sphere(t_v4df const p, t_v4df const d,
			Camera const *restrict const cam,
			void const *restrict const obj_ptr) NON_NULL((3,4));
t_v4df	rt_normal_cone(t_v4df const p, t_v4df const d,
			Camera const *restrict const cam,
			void const *restrict const obj_ptr) NON_NULL((3,4));
t_v4df	rt_normal_plane(t_v4df const p, t_v4df const d,
			Camera const *restrict const cam,
			void const *restrict const obj_ptr) NON_NULL((3,4));
t_v4df	rt_normal_cylinder(t_v4df const p, t_v4df const d,
			Camera const *restrict const cam,
			void const *restrict const obj_ptr) NON_NULL((3,4));

/*
** Objects uv-mapping calcs:
*/
Uint32	rt_uv_sphere(SDL_Surface *restrict const tex, t_v4df const n)
			NON_NULL((1));
Uint32	rt_uv_cone(SDL_Surface *restrict const tex, t_v4df const n)
			NON_NULL((1));
Uint32	rt_uv_plane(SDL_Surface *restrict const tex, t_v4df const n)
			NON_NULL((1));
Uint32	rt_uv_cylinder(SDL_Surface *restrict const tex, t_v4df const n)
			NON_NULL((1));

/*
** Calc light:
*/
Color	rt_lightning(Scene *restrict const scene,
			t_clhelp *restrict const h,
			t_v4df const d) NON_NULL((1,2));


Environment	**rt_prepare_threading(Environment *restrict const env);
void		rt_free_threading(Environment **env_dups);

#endif
