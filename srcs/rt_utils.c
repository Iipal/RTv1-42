/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:44:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/16 15:48:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Vec	*rt_cp_vec(Vec *v, double x, double y, double z)
{
	*v = (Vec){x, y, z};
	return (v);
}

inline Vec	*rt_cp_vvec(Vec *dst, Vec src)
{
	*dst = (Vec){src.x, src.y, src.z};
	return (dst);
}

inline Ray	*u_cp_ray(Ray *r, Vec origin, Vec direction)
{
	*r = (Ray){origin, direction};
	return (r);
}