/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:46:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/09/02 21:51:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static __always_inline t_v4df	s_camera_rot_x(t_v4df d, t_v4df const dir)
{
	double_t const	temp = Y(d);

	Y(d) = temp * COS_RAD(X(dir)) + Z(d) * SIN_RAD(X(dir));
	Z(d) = -temp * SIN_RAD(X(dir)) + Z(d) * COS_RAD(X(dir));
	return (d);
}

static __always_inline t_v4df	s_camera_rot_y(t_v4df d, t_v4df const dir)
{
	double_t const	temp = X(d);

	X(d) = temp * COS_RAD(Y(dir)) + Z(d) * SIN_RAD(Y(dir));
	Z(d) = -temp * SIN_RAD(Y(dir)) + Z(d) * COS_RAD(Y(dir));
	return (d);
}

static __always_inline t_v4df	s_camera_rot_z(t_v4df d, t_v4df const dir)
{
	double_t const	temp = X(d);

	X(d) = temp * COS_RAD(Z(dir)) - Y(d) * SIN_RAD(Z(dir));
	Y(d) = temp * SIN_RAD(Z(dir)) + Y(d) * COS_RAD(Z(dir));
	return (d);
}

t_v4df					rt_camera_rotate(t_v4df d, t_v4df const dir)
{
	if (X(dir))
		d = s_camera_rot_x(d, dir);
	if (Y(dir))
		d = s_camera_rot_y(d, dir);
	if (Z(dir))
		d = s_camera_rot_z(d, dir);
	return (d);
}
