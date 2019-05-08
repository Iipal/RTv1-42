/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:23:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/08 16:05:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline Color	add_trace_ray(Environment *env, Vec d)
{
	fDot			t;
	bool			is_figure;
	int32_t			i;

	i = -1;
	while (env->s.ins_objs > ++i)
		if ((is_figure = rt_intersection(env, d, &t, i)))
		{
			IFDO(t.x >= TMIN && t.x <= TMAX, env->s.cobj = t.x);
			IFDO(t.y >= TMIN && t.y <= TMAX, env->s.cobj = t.y);
			break ;
		}
	return (is_figure ? rt_calculate_light(env, i, d) : (Color){0, 0, 0});
}

void				rt_raytracing(Environment *env)
{
	Dot		i;
	Color	curr_color;
	Vec		d;

	i.y = RT_SY;
	curr_color = (Color){0, 0, 0};
	while (RT_EY > ++(i.y) && (i.x = RT_SX))
		while (RT_EX > ++(i.x))
		{
			d = (Vec){i.x * WIN_X / (1000.0 * WIN_X),
				i.y * WIN_Y / (1000.0 * WIN_Y), 1.0};
			curr_color = add_trace_ray(env, d);
			sdl_pixelput_canvas(env->sdl->wsurf,
				(Dot){i.x, i.y}, (Dot){WIN_X, WIN_Y}, curr_color);
		}
}
