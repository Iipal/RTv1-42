/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:44:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/15 19:04:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool		u_inrangev(const Vector v,
				const bool check_min, const bool check_max)
{
	if (check_max
	&& (MAX_X < X(v) || MAX_Y < Y(v) || MAX_Z < Z(v)))
		return (false);
	if (check_min
	&& (MIN_X > X(v) || MIN_Y > Y(v) || MIN_Z > Z(v)))
		return (false);
	return (true);
}

inline double_t	u_inranged(const double_t v,
				const bool check_min, const bool check_max)
{
	if (check_max && MAX_X < v)
		return (MAX_X);
	if (check_min && MIN_X > v)
		return (MIN_X);
	return (v);
}

Vector			u_inrange_dir_max(Vector dir)
{
	Vector	out;

	out = dir;
	if (MAX_ROT_ANGLE < X(out))
		while (MAX_ROT_ANGLE < X(out))
			X(out) -= MAX_ROT_ANGLE;
	if (MAX_ROT_ANGLE < Y(out))
		while (MAX_ROT_ANGLE < Y(out))
			Y(out) -= MAX_ROT_ANGLE;
	if (MAX_ROT_ANGLE < Z(out))
		while (MAX_ROT_ANGLE < Z(out))
			Y(out) -= MAX_ROT_ANGLE;
	return (out);
}

Vector			u_inrange_dir_min(Vector dir)
{
	Vector	out;

	out = dir;
	if (MIN_ROT_ANGLE > X(out))
		while (MIN_ROT_ANGLE > X(out))
			X(out) += MAX_ROT_ANGLE;
	if (MIN_ROT_ANGLE > Y(out))
		while (MIN_ROT_ANGLE > Y(out))
			Y(out) += MAX_ROT_ANGLE;
	if (MIN_ROT_ANGLE > Z(out))
		while (MIN_ROT_ANGLE > Z(out))
			Y(out) += MAX_ROT_ANGLE;
	return (out);
}
