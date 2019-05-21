/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 19:54:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/21 18:56:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Color		rt_raytracing(Environment *const env, Vector d)
{
	t_clhelp		h;
	Object			*obj;

	d = (Vector){VNORM(d)};
	obj = rt_closest_inter(env->s.cam.pos, d, env);
	NO_R(obj, U_CLR_BLACK);
	h.p = env->s.cam.pos + VMUL(d, env->s.cobj);
	h.n = obj->fn_normal_calc(h.p, d, &env->s.cam, obj);
	h.n = (Vector){VNORM(h.n)};
	return (env->flags.no_calc_light
		? obj->clr : rt_calc_light(env, &h, obj, d));
}
