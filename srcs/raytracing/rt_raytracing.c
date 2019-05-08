/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:23:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/08 15:12:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	Calculate point light type
*/

static inline Color	add_compute_light(t_clhelp h)
{
	double		i;
	Color		tmp;
	const Vec	x = {h.l.pos.x - h.p.x, h.l.pos.y - h.p.y, h.l.pos.z - h.p.z};
	const float	dot_nl = VDOT(h.n, x);
	double		r_dot_v;
	Vec			r;

	tmp = h.clr;
	i = 0.0;
	if (.0f < dot_nl)
		i += h.l.intensity * dot_nl / (VLEN(h.n) * VLEN(x));
	if (0 <= h.s)
	{
		r = (Vec){2.0f * h.n.x * dot_nl - x.x, 2.0f * h.n.y * dot_nl - x.y,
				2.0f * h.n.z * dot_nl - x.z};
		r_dot_v = VDOT(r, h.v);
		if (0.0f < r_dot_v)
			i += h.l.intensity * pow(r_dot_v / (VLEN(r) * VLEN(h.v)), h.s);
	}
	return (0.0f < i ? *sdl_clrs_add(&h.clr, *sdl_clr_mul(&tmp, i)) : h.clr);
}

static inline Color	add_calculate_light(Environment *env, int32_t i, Vec d)
{
	t_lhelp	lh;

	if (env->s.ins_objs <= i)
		i = env->s.ins_objs - 1;
	lh.cd = (Vec){env->s.cobj * d.x,
				env->s.cobj * d.y,
				env->s.cobj * d.z};
	lh.p = (Vec){env->s.cam.pos.x + lh.cd.x,
				env->s.cam.pos.y + lh.cd.y,
				env->s.cam.pos.z + lh.cd.z};
	lh.n = (Vec){lh.p.x - env->s.objs[i].pos.x,
				lh.p.y - env->s.objs[i].pos.y,
				lh.p.z - env->s.objs[i].pos.z};
	lh.n = (Vec){lh.n.x / VLEN(lh.n),
				lh.n.y / VLEN(lh.n),
				lh.n.z / VLEN(lh.n)};
	return (add_compute_light((t_clhelp){env->s.objs[i].clr, lh.p, lh.n,
				env->s.l, env->s.objs[i].spec, (Vec){-d.x, -d.y, -d.z}}));
}

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
	return (is_figure ? add_calculate_light(env, i, d) : (Color){0, 0, 0});
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
