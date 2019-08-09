/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl_camera_speed_movements.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:14:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/08 23:48:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_camera_speed_movements(double_t *restrict const cam_speed)
{
	if (IS_BIT(g_isr_flags, ISR_SPEEDUP))
	{
		if (MOVE_SPEED_PERCENT_SUP > *cam_speed)
			*cam_speed += MOVE_SPEED_PERCENT_STEP;
	}
	else if (MOVE_SPEED_PERCENT_DEFAULT < *cam_speed)
		*cam_speed -= MOVE_SPEED_PERCENT_STEP;
	if (IS_BIT(g_isr_flags, ISR_SPEEDDOWN))
	{
		if (MOVE_SPEED_PERCENT_SDOWN < *cam_speed)
			*cam_speed -= MOVE_SPEED_PERCENT_STEP;
	}
	else if (MOVE_SPEED_PERCENT_DEFAULT > *cam_speed)
		*cam_speed += MOVE_SPEED_PERCENT_STEP;
}
