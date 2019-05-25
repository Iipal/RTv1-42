/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:46:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/23 10:39:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Vector	rt_camera_rotate(Vector d, const Vector dir)
{
	double_t	temp;

	if (X(dir))
	{
		temp = Y(d);
		Y(d) = temp * COS_RAD(X(dir)) + Z(d) * SIN_RAD(X(dir));
		Z(d) = -temp * SIN_RAD(X(dir)) + Z(d) * COS_RAD(X(dir));
	}
	if (Y(dir))
	{
		temp = X(d);
		X(d) = temp * COS_RAD(Y(dir)) + Z(d) * SIN_RAD(Y(dir));
		Z(d) = -temp * SIN_RAD(Y(dir)) + Z(d) * COS_RAD(Y(dir));
	}
	if (Z(dir))
	{
		temp = X(d);
		X(d) = temp * COS_RAD(Z(dir)) - Y(d) * SIN_RAD(Z(dir));
		Y(d) = temp * SIN_RAD(Z(dir)) + Y(d) * COS_RAD(Z(dir));
	}
	return (d);
}
