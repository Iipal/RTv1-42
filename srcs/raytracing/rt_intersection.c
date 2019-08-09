/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 14:00:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline __v2df	add_intersection(__v4df const o, __v4df const d,
							const Object *restrict const obj)
{
	__v4df const	x = o - obj->pos;
	__v4df const	k = obj->fn_inter_calc(x, d, obj);
	double_t const	disc = VDISC(X(k), Y(k), Z(k));
	__v2df			out;

	out = (__v2df){-1.0, -1.0};
	if (.0 <= disc)
		out = (__v2df){ (-Y(k) + sqrt(disc)) / (2.0 * X(k)),
					(-Y(k) - sqrt(disc)) / (2.0 * X(k)) };
	return (out);
}

static inline __v2df	add_plane_inter(__v4df const o, __v4df const d,
							const Object *restrict const obj)
{
	double_t const	d_dot_v = v_dot(d, obj->dir);
	__v2df			out;

	out = (__v2df){-1.0, -1.0};
	if (d_dot_v)
		X(out) = -v_dot(o - obj->pos, obj->dir) / d_dot_v;
	return (out);
}

Object					*rt_closest_inter(__v4df const o, __v4df const d,
									Environment *restrict const env)
{
	Object	*out_obj;
	__v2df	t;
	size_t	i;

	i = ~0UL;
	out_obj = NULL;
	env->scene.cam.t = env->tmax;
	while (++i < env->scene.ins_objs)
	{
		if (plane == env->scene.objs[i].type)
			t = add_plane_inter(o, d, &env->scene.objs[i]);
		else
			t = add_intersection(o, d, &env->scene.objs[i]);
		if (X(t) > env->tmin && X(t) < env->tmax && X(t) < env->scene.cam.t)
		{
			env->scene.cam.t = X(t);
			out_obj = &env->scene.objs[i];
		}
		if (Y(t) > env->tmin && Y(t) < env->tmax && Y(t) < env->scene.cam.t)
		{
			env->scene.cam.t = Y(t);
			out_obj = &env->scene.objs[i];
		}
	}
	return (out_obj);
}
