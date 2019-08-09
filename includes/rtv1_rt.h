/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:02:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 08:44:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_RT_H
# define RTV1_RT_H

# include "rtv1_structs.h"

Color	rt_raytracing(Environment *restrict const env, __v4df d);

__v4df	rt_camera_rotate(__v4df d, __v4df const dir);

/*
** Objects intersection calc:
*/
Object	*rt_closest_inter(__v4df const o, __v4df const d,
			Environment *restrict const env);
__v4df	rt_inter_sphere(__v4df const x, __v4df const d,
			void const *restrict const obj_ptr);
__v4df	rt_inter_cone(__v4df const x, __v4df const d,
			void const *restrict const obj_ptr);
__v4df	rt_inter_plane(__v4df const x, __v4df const d,
			void const *restrict const obj_ptr);
__v4df	rt_inter_cylinder(__v4df const x, __v4df const d,
			void const *restrict const obj_ptr);

/*
** Objects normals calcs:
*/
__v4df	rt_normal_sphere(__v4df const p, __v4df const d,
			Camera const *restrict const cam,
			void const *restrict const obj_ptr);
__v4df	rt_normal_cone(__v4df const p, __v4df const d,
			Camera const *restrict const cam,
			void const *restrict const obj_ptr);
__v4df	rt_normal_plane(__v4df const p, __v4df const d,
			Camera const *restrict const cam,
			void const *restrict const obj_ptr);
__v4df	rt_normal_cylinder(__v4df const p, __v4df const d,
			Camera const *restrict const cam,
			void const *restrict const obj_ptr);

/*
** Objects uv-mapping calcs:
*/
Uint32	rt_uv_sphere(SDL_Surface *restrict const tex, __v4df const n);
Uint32	rt_uv_cone(SDL_Surface *restrict const tex, __v4df const n);
Uint32	rt_uv_plane(SDL_Surface *restrict const tex, __v4df const n);
Uint32	rt_uv_cylinder(SDL_Surface *restrict const tex, __v4df const n);

/*
** Calc light:
*/
Color	rt_calc_light(Environment *restrict const env,
			t_clhelp *restrict const h,
			__v4df const d);

#endif
