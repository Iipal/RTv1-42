/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:46:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/28 18:59:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline Vector	add_camera_rot_x(Vector d, Vector dir)
{
	const double_t	temp = Y(d);

	Y(d) = temp * COS_RAD(X(dir)) + Z(d) * SIN_RAD(X(dir));
	Z(d) = -temp * SIN_RAD(X(dir)) + Z(d) * COS_RAD(X(dir));
	return (d);
}

static inline Vector	add_camera_rot_y(Vector d, Vector dir)
{
	const double_t	temp = X(d);

	X(d) = temp * COS_RAD(Y(dir)) + Z(d) * SIN_RAD(Y(dir));
	Z(d) = -temp * SIN_RAD(Y(dir)) + Z(d) * COS_RAD(Y(dir));
	return (d);
}

static inline Vector	add_camera_rot_z(Vector d, Vector dir)
{
	const double_t	temp = X(d);

	X(d) = temp * COS_RAD(Z(dir)) - Y(d) * SIN_RAD(Z(dir));
	Y(d) = temp * SIN_RAD(Z(dir)) + Y(d) * COS_RAD(Z(dir));
	return (d);
}

inline Vector			rt_camera_rotate(Vector d, const Vector dir)
{
	if (X(dir))
		d = add_camera_rot_x(d, dir);
	if (Y(dir))
		d = add_camera_rot_y(d, dir);
	if (Z(dir))
		d = add_camera_rot_z(d, dir);
	return (d);
}
