/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_uv_mapping.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 12:52:32 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/11 20:31:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Uint32	rt_uv_sphere(SDL_Surface *restrict const tex, const __v4df n)
{
	__v2si	uv;

	uv = (__v2si){ (0.5 + atan2(Z(n), X(n)) / (2.0 * M_PI)) * tex->w,
					tex->h - ((0.5 - asin(Y(n)) / M_PI) * tex->h) };
	return (((const Uint32*)tex->pixels)[Y(uv) * tex->w + X(uv)]);
}

inline Uint32	rt_uv_cone(SDL_Surface *restrict const tex, const __v4df n)
{
	return (rt_uv_sphere(tex, n));
}

inline Uint32	rt_uv_plane(SDL_Surface *restrict const tex, const __v4df n)
{
	return (rt_uv_sphere(tex, n));
}

inline Uint32	rt_uv_cylinder(SDL_Surface *restrict const tex, const __v4df n)
{
	return (rt_uv_sphere(tex, n));
}
