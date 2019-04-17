/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:44:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/17 13:48:57 by tmaluh           ###   ########.fr       */
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

inline bool	rt_inrange(Vec v, bool check_min, bool check_max)
{
	if (check_max)
		if (MAX_X < v.x || MAX_Y < v.y || MAX_Z < v.z)
			return (false);
	if (check_min)
		if (MIN_X > v.x || MIN_Y > v.y || MIN_Z > v.z)
			return (false);
	return (true);
}
