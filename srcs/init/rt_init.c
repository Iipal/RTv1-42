/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/10 10:28:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

uint32_t g_isr_flags = 0U;
uint16_t g_flags = 0;

bool	rt_main_env_init(Environment *const env)
{
	MEM(Sdl, env->sdl, 1, E_ALLOC);
	NO_F(sdl_init(env->sdl, WIN_X, WIN_Y, RTV1_TITLE));
	env->flags = (Flags){DEF_FPS_TEXT_COLOR,
						DEF_FPS_REFRESH_TIMER,
						DEF_VIEWPORT_SCALE,
						DEF_AMBIENT_LIGHT,
						DEF_ANTI_ALIASING};
	env->cam_speed = MOVE_SPEED_PERCENT_DEFAULT;
	return (true);
}
