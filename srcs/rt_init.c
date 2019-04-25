/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/25 19:52:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool		rt_init(Environment *env)
{
	MEM(Sdl, env->sdl, 1, E_ALLOC);
	IFDOR(!sdl_init(env->sdl, WIN_X, WIN_Y, RTV1_TITLE), rt_free(&env), false);
	env->cam_speed = MOVE_BOOST_PERCENT_DEFAULT;
	return (true);
}
