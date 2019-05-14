/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:23:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 18:08:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline Color	add_prepare_light_calc(Environment *env,
								const t_v d, const Object *obj)
{
	t_clhelp	h;

	if (!obj)
		return (CLR_BLACK);
	C(t_clhelp, &h, 1);
	h.p = env->s.cam.pos + VMULR(d, env->s.cobj);
	h.n = h.p - obj->pos;
	h.n = (t_v){X(h.n) / VLEN(h.n), Y(h.n) / VLEN(h.n), Z(h.n) / VLEN(h.n)};
	return (rt_calculate_light(env, &h, obj, d));
}

void		rt_raytracing(Environment *env)
{
	Dot			i;
	t_v			d;

	i.y = RT_CANVAS_STARTY;
	while (RT_CANVAS_ENDY > ++(i.y) && (i.x = RT_CANVAS_STARTX))
		while (RT_CANVAS_ENDX > ++(i.x))
		{
			env->t_max = TMAX;
			env->t_min = TMIN;
			d = (t_v) {i.x * WIN_X / (1000.0f * WIN_X),
				i.y * WIN_Y / (1000.0f * WIN_Y), env->flags.viewport_scale};
			sdl_pixelput(env->sdl->wsurf,
				CONVERT_FROM_CANVAS(i.x, i.y, WIN_X, WIN_Y),
				add_prepare_light_calc(env, d,
					rt_closest_inter(env->s.cam.pos, d, env)));
		}
}
