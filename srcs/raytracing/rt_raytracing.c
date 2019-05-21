/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 19:54:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/21 15:42:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Color		rt_raytracing(Environment *const env, const Vector d)
{
	t_clhelp		h;
	double_t		len_n;
	const Object	*obj = rt_closest_inter(env->s.cam.pos, d, env);

	NO_R(obj, U_CLR_BLACK);
	h.p = env->s.cam.pos + VMULR(d, env->s.cobj);
	h.n = obj->fn_normal_calc(h.p, d, &env->s.cam, obj);
	len_n = VLEN(h.n);
	h.n = (Vector){X(h.n) / len_n, Y(h.n) / len_n, Z(h.n) / len_n};
	return (env->flags.no_calc_light
		? obj->clr : rt_calc_light(env, &h, obj, d));
}
