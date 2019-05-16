/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_camera_speed_movements.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:14:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/16 15:03:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_camera_speed_movements(double_t *cam_s,
				const bool is_speed_up, const bool is_speed_down)
{
	if (is_speed_up)
	{
		if (MOVE_SPEED_PERCENT_SUP > *cam_s)
			*cam_s += MOVE_SPEED_PERCENT_STEP;
	}
	else if (MOVE_SPEED_PERCENT_DEFAULT < *cam_s)
		*cam_s -= MOVE_SPEED_PERCENT_STEP;
	if (is_speed_down)
	{
		if (MOVE_SPEED_PERCENT_SDOWN < *cam_s)
			*cam_s -= MOVE_SPEED_PERCENT_STEP;
	}
	else if (MOVE_SPEED_PERCENT_DEFAULT > *cam_s)
		*cam_s += MOVE_SPEED_PERCENT_STEP;
}
