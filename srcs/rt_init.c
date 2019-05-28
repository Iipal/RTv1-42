/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/28 19:29:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_init(Environment *restrict env)
{
	MEM(Sdl, env->sdl, 1, E_ALLOC);
	NODO_F(sdl_init(env->sdl, WIN_X, WIN_Y, RTV1_TITLE), rt_free(&env));
	env->cam_speed = MOVE_SPEED_PERCENT_DEFAULT;
	env->flags = (Flags){DEF_VIEWPORT_SCALE,
						DEF_SHADOW_BRIGHT,
						DEF_FPS_TEXT_COLOR, false,
						DEF_FPS_REFRESH_TIMER, false,
						DEF_DEBUG_MODE,
						DEF_NOT_CALC_LIGHT,
						DEF_PRINT_USAGE};
	return (true);
}
