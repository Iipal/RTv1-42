/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/17 18:59:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_init_objects(Environment *env)
{
	IFDO(env->s.sp.is, ++env->max_objs);
	IFDO(0 < env->max_objs,
		NOTIS_F(env->obj = (Object*)malloc(sizeof(Object) * env->max_objs)));
	*(env->obj) = (Object){
		env->s.sp.pos, env->s.sp.clr, env->s.sp.radius, env->s.sp.spec};
	return (true);
}

bool		rt_init(Environment *env)
{
	MEM(Sdl, env->sdl, 1, E_ALLOC);
	IFDOR(!sdl_init(env->sdl, WIN_X, WIN_Y, RTV1_TITLE), rt_free(&env), false);
	NOTIS(E_ALLOC, add_init_objects(env), rt_free(&env), false);
	return (true);
}
