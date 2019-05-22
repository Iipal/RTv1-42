/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:46:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/22 14:38:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Vector	rt_camera_rotate(Vector d, const Vector dir)
{
	double_t	temp;

	if (X(dir))
	{
		temp = Y(d);
		Y(d) = temp * cos(X(dir)) + Z(d) * sin(X(dir));
		Z(d) = -temp * sin(X(dir)) + Z(d) * cos(Y(dir));
	}
	if (Y(dir))
	{
		temp = X(d);
		X(d) = temp * cos(Y(dir)) + Z(d) * sin(Y(dir));
		Z(d) = -temp * sin(Y(dir)) + Z(d) * cos(Y(dir));
	}
	return (d);
}
