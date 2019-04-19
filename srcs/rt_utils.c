/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:44:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/19 12:30:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Vec		*u_cp_vec(Vec *v, double x, double y, double z)
{
	*v = (Vec){x, y, z};
	return (v);
}

inline Vec		*u_cp_vvec(Vec *dst, Vec src)
{
	*dst = (Vec){src.x, src.y, src.z};
	return (dst);
}

inline bool		u_inrange(Vec v, bool check_min, bool check_max)
{
	if (check_max)
		if (MAX_X < v.x || MAX_Y < v.y || MAX_Z < v.z)
			return (false);
	if (check_min)
		if (MIN_X > v.x || MIN_Y > v.y || MIN_Z > v.z)
			return (false);
	return (true);
}

inline Vec		u_sub_vec(Vec a, Vec b)
{
	Vec ret;

	ret = (Vec){a.x - b.x,
				a.y - b.y,
				a.z - b.z};
	return (ret);
}

inline float	u_mul_vec(Vec a, Vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
