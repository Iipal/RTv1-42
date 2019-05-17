/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 19:54:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 16:01:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline Color		rt_raytracing(Environment *env, const Vector d)
{
	t_clhelp		h;
	const Object	*obj = rt_closest_inter(env->s.cam.pos, d, env);

	NO_R(obj, CLR_BLACK);
	h.p = env->s.cam.pos + VMULR(d, env->s.cobj);
	h.n = obj->fn_normal_calc(h.p, d, &env->s.cam, obj);
	h.n = (Vector){X(h.n) / VLEN(h.n), Y(h.n) / VLEN(h.n), Z(h.n) / VLEN(h.n)};
	return (rt_calculate_light(env, &h, obj, d));
}
