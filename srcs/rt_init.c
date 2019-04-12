/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 11:32:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_init(Environment *env)
{
	MEM(Sdl, env->sdl, 1, E_ALLOC);
	IFDOR(!sdl_init(env->sdl, env->w_size.x, env->w_size.y, RTV1_TITLE),
		rt_free(&env), false);
	return (true);
}
