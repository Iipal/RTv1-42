/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/09/02 21:51:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static __always_inline t_v2df	s_intersection(t_v4df const o, t_v4df const d,
							Object const *const obj)
{
	t_v4df const	x = o - obj->pos;
	t_v4df const	k = obj->fn_inter_calc(x, d, obj);
	double_t const	disc = VDISC(X(k), Y(k), Z(k));
	t_v2df			out;

	out = (t_v2df){ -1.0, -1.0 };
	if (.0 <= disc)
		out = (t_v2df){ (-Y(k) + sqrt(disc)) / (2.0 * X(k)),
					(-Y(k) - sqrt(disc)) / (2.0 * X(k)) };
	return (out);
}

static __always_inline t_v2df	s_plane_inter(t_v4df const o, t_v4df const d,
									t_v4df const pos, t_v4df const dir)
{
	double_t const	d_dot_v = v_dot(d, dir);
	t_v2df			out;

	out = (t_v2df){ -1.0, -1.0 };
	if (d_dot_v)
		X(out) = -v_dot(o - pos, dir) / d_dot_v;
	return (out);
}

Object					*rt_intersection(t_v4df const o, t_v4df const d,
									Scene *restrict const scene)
{
	Object	*obj;
	Object	*out_obj;
	t_v2df	t;
	ssize_t	i;

	out_obj = NULL;
	scene->cam.t = scene->tmax;
	i = scene->ins_objs;
	while (0 <= --i)
	{
		obj = &scene->objs[i];
		t = !(plane == obj->type) ? s_intersection(o, d, obj)
					: s_plane_inter(o, d, obj->pos, obj->dir);
		if (X(t) > scene->tmin && X(t) < scene->tmax && X(t) < scene->cam.t)
		{
			scene->cam.t = X(t);
			out_obj = obj;
		}
		if (Y(t) > scene->tmin && Y(t) < scene->tmax && Y(t) < scene->cam.t)
		{
			scene->cam.t = Y(t);
			out_obj = obj;
		}
	}
	return (out_obj);
}
