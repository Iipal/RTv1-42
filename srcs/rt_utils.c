/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:44:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/09 05:01:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_v4df	u_inrange_dir_max(t_v4df dir)
{
	t_v4df	out;

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

t_v4df	u_inrange_dir_min(t_v4df dir)
{
	t_v4df	out;

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
