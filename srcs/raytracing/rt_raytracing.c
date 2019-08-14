/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 19:54:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/14 09:00:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

Color	rt_raytracing(Scene *restrict const scene, __v4df d, double_t const al)
{
	t_clhelp	h;
	Object		*obj;

	d = v_norm(rt_camera_rotate(d, scene->cam.dir));
	obj = rt_intersection(scene->cam.pos, d, scene);
	if (!obj)
		return (U_CLR_BLACK);
	else if (IS_BIT(g_flags, F_BIT_NCL) && !IS_BIT(g_flags, F_BIT_TEX))
		return (obj->clr);
	else
	{
		h.curr_clr = obj->clr;
		h.p = scene->cam.pos + v_mul_d(d, scene->cam.t);
		if (IS_BIT(g_flags, F_BIT_TEX))
			h.curr_clr.hex = obj->fn_uv(obj->texture, v_norm(h.p - obj->pos));
		if (IS_BIT(g_flags, F_BIT_NCL))
			return (h.curr_clr);
		h.n = v_norm(obj->fn_normal_calc(h.p, d, &scene->cam, obj));
		h.obj_spec = obj->spec;
		h.al = al;
	}
	return (rt_lightning(scene, &h, -d));
}
