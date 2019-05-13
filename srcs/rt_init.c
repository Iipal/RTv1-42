/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/13 19:57:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_init(Environment *env)
{
	MEM(Sdl, env->sdl, 1, E_ALLOC);
	NODO_F(sdl_init(env->sdl, WIN_X, WIN_Y, RTV1_TITLE), rt_free(&env));
	env->cam_speed = MOVE_SPEED_PERCENT_DEFAULT;
	env->flags = (Flags){1.0f, 100.0f};
	return (true);
}
