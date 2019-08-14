/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/14 21:28:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static __always_inline __v2df	s_intersection(__v4df const o, __v4df const d,
							Object const *const obj)
{
	__v4df const	x = o - obj->pos;
	__v4df const	k = obj->fn_inter_calc(x, d, obj);
	double_t const	disc = VDISC(X(k), Y(k), Z(k));
	__v2df			out;

	out = (__v2df){ -1.0, -1.0 };
	if (.0 <= disc)
		out = (__v2df){ (-Y(k) + sqrt(disc)) / (2.0 * X(k)),
					(-Y(k) - sqrt(disc)) / (2.0 * X(k)) };
	return (out);
}

static __always_inline __v2df	s_plane_inter(__v4df const o, __v4df const d,
									__v4df const pos, __v4df const dir)
{
	double_t const	d_dot_v = v_dot(d, dir);
	__v2df			out;

	out = (__v2df){ -1.0, -1.0 };
	if (d_dot_v)
		X(out) = -v_dot(o - pos, dir) / d_dot_v;
	return (out);
}

Object					*rt_intersection(__v4df const o, __v4df const d,
									Scene *restrict const scene)
{
	Object	*obj;
	Object	*out_obj;
	__v2df	t;
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
