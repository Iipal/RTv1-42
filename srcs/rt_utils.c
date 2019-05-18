/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:44:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/19 00:32:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
