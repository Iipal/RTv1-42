/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/14 14:12:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

uint32_t g_isr_flags = 0U;
uint16_t g_flags = 0;
const size_t				g_threads_num = 32UL;
struct s_tpool *restrict	g_threads_pool = NULL;

bool	rt_main_env_init(Environment *const env)
{
	NO_F(g_threads_pool = tpool_create(g_threads_num));
	MEM(Sdl, env->sdl, 1, E_ALLOC);
	NO_F(sdl_init(env->sdl, WIN_X, WIN_Y, RTV1_TITLE));
	env->flags = (Flags) { DEF_FPS_TEXT_COLOR,
						DEF_FPS_REFRESH_TIMER,
						DEF_VIEWPORT_SCALE,
						DEF_AMBIENT_LIGHT,
						DEF_ANTI_ALIASING };
	env->cam_speed = MOVE_SPEED_PERCENT_DEFAULT;
	return (true);
}
