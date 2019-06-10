/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:46:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/10 11:24:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline __attribute__((__always_inline__)) __v4df	add_camera_rot_x(
												__v4df d, __v4df dir)
{
	const double_t	temp = Y(d);

	Y(d) = temp * COS_RAD(X(dir)) + Z(d) * SIN_RAD(X(dir));
	Z(d) = -temp * SIN_RAD(X(dir)) + Z(d) * COS_RAD(X(dir));
	return (d);
}

static inline __attribute__((__always_inline__)) __v4df	add_camera_rot_y(
												__v4df d, __v4df dir)
{
	const double_t	temp = X(d);

	X(d) = temp * COS_RAD(Y(dir)) + Z(d) * SIN_RAD(Y(dir));
	Z(d) = -temp * SIN_RAD(Y(dir)) + Z(d) * COS_RAD(Y(dir));
	return (d);
}

static inline __attribute__((__always_inline__)) __v4df	add_camera_rot_z(
												__v4df d, __v4df dir)
{
	const double_t	temp = X(d);

	X(d) = temp * COS_RAD(Z(dir)) - Y(d) * SIN_RAD(Z(dir));
	Y(d) = temp * SIN_RAD(Z(dir)) + Y(d) * COS_RAD(Z(dir));
	return (d);
}

__v4df					rt_camera_rotate(__v4df d, const __v4df dir)
{
	if (X(dir))
		d = add_camera_rot_x(d, dir);
	if (Y(dir))
		d = add_camera_rot_y(d, dir);
	if (Z(dir))
		d = add_camera_rot_z(d, dir);
	return (d);
}
