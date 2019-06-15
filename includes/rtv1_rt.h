/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:02:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/15 18:04:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_RT_H
# define RTV1_RT_H

# include "rtv1_structs.h"

extern Color	rt_raytracing(Environment *restrict const env, __v4df d);

extern __v4df	rt_camera_rotate(__v4df d, const __v4df dir);

/*
** Objects intersection calc:
*/
Object			*rt_closest_inter(const __v4df o, const __v4df d,
							Environment *restrict const env);
extern __v4df	rt_inter_sphere(const __v4df x, const __v4df d,
							void const *restrict const obj_ptr);
extern __v4df	rt_inter_cone(const __v4df x, const __v4df d,
							void const *restrict const obj_ptr);
extern __v4df	rt_inter_plane(const __v4df x, const __v4df d,
							void const *restrict const obj_ptr);
extern __v4df	rt_inter_cylinder(const __v4df x, const __v4df d,
							void const *restrict const obj_ptr);

/*
** Objects nomrals calcs:
*/
extern __v4df	rt_normal_sphere(const __v4df p, const __v4df d,
							Camera const *restrict const cam,
							void const *restrict const obj_ptr);
extern __v4df	rt_normal_cone(const __v4df p, const __v4df d,
							Camera const *restrict const cam,
							void const *restrict const obj_ptr);
extern __v4df	rt_normal_plane(const __v4df p, const __v4df d,
							Camera const *restrict const cam,
							void const *restrict const obj_ptr);
extern __v4df	rt_normal_cylinder(const __v4df p, const __v4df d,
							Camera const *restrict const cam,
							void const *restrict const obj_ptr);

/*
** Objects uv-mapping calcs:
*/
extern Uint32	rt_uv_sphere(SDL_Surface *restrict const tex, const __v4df n);
extern Uint32	rt_uv_cone(SDL_Surface *restrict const tex, const __v4df n);
extern Uint32	rt_uv_plane(SDL_Surface *restrict const tex, const __v4df n);
extern Uint32	rt_uv_cylinder(SDL_Surface *restrict const tex, const __v4df n);

/*
** Calc light:
*/
Color			rt_calc_light(Environment *restrict const env,
							t_clhelp *restrict const h,
							const __v4df d);

#endif
