/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:14:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/26 19:53:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_camera_speed(double *cam_s, bool is_speed_up, bool is_speed_down)
{
	if (is_speed_up)
	{
		if (MOVE_BOOST_PERCENT_SUP > *cam_s)
			*cam_s += MOVE_BOOST_PERCENT_STEP;
	}
	else if (MOVE_BOOST_PERCENT_DEFAULT < *cam_s)
		*cam_s -= MOVE_BOOST_PERCENT_STEP;
	if (is_speed_down)
	{
		if (MOVE_BOOST_PERCENT_SDOWN < *cam_s)
			*cam_s -= MOVE_BOOST_PERCENT_STEP;
	}
	else if (MOVE_BOOST_PERCENT_DEFAULT > *cam_s)
		*cam_s += MOVE_BOOST_PERCENT_STEP;
}
