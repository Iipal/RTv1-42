/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 11:06:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/03 09:53:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline fDot	add_intersection(const Vector o,
									const Vector d,
									const Object *restrict const obj)
{
	const Vector	x = o - obj->pos;
	const Vector	k = obj->fn_inter_calc(x, d, obj);
	const double_t	disc = VDISC(k);
	fDot			out;

	out = (fDot){-1, -1};
	if (.0f <= disc)
		out = (fDot){ (-Y(k) + sqrt(disc)) / (2.0f * X(k)),
					(-Y(k) - sqrt(disc)) / (2.0f * X(k)) };
	return (out);
}

static inline fDot	add_plane_inter(const Vector o, const Vector d,
						const Object *restrict const obj)
{
	const double_t	d_dot_v = u_vdot(d, obj->dir);
	fDot			out;

	out = (fDot){-1, -1};
	if (d_dot_v)
		X(out) = -u_vdot(o - obj->pos, obj->dir) / d_dot_v;
	return (out);
}

Object				*rt_closest_inter(const Vector o,
									const Vector d,
									Environment *restrict const env)
{
	fDot				t;
	size_t				i;
	Object *restrict	out_obj;

	i = ~0L;
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
