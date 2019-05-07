/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:23:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/07 17:24:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline bool	add_inter(Environment *env, Vec d, fDot *t, int32_t i)
{
	const int16_t	r = env->s.objs[i].radius;
	const Vec		ds = u_sub_vec(env->s.cam.pos, env->s.objs[i].pos);
	const Vec		k = {VMUL(d, d), 2.0f * VMUL(ds, d), VMUL(ds, ds) - r * r};
	const float		disc = k.y * k.y - 4 * k.x * k.z;

	ISR(.0f > disc, false);
	t->x = (-k.y + sqrt(disc)) / (2 * k.x);
	t->y = (-k.y - sqrt(disc)) / (2 * k.x);
	return (true);
}

/*
**	Calculate point light type
*/

static inline Color	add_compute_light(Color clr, Vec p, Vec n, Light l,
	float s, Vec V)
{
	Color			tmp;
	const Vec		x = (Vec){l.pos.x - p.x, l.pos.y - p.y, l.pos.z - p.z};
	const double	dot_nl = VDOT(n, x);

	tmp = clr;
	if (.0f < dot_nl && 0.0f < l.intensity)
	{
		sdl_clrs_add(&clr, *sdl_clr_mul(&tmp,
			l.intensity * dot_nl / (VLEN(n) * VLEN(x))));
	}
	if (0 <= s)
	{
		const Vec R = (Vec){2.0f * n.x * dot_nl - x.x,
							2.0f * n.y * dot_nl - x.y,
							2.0f * n.z * dot_nl - x.z};
		const float	r_dot_v = VDOT(R, V);
		if (0.0f < r_dot_v)
		{
			tmp = clr;
			sdl_clrs_add(&clr, *sdl_clr_mul(&tmp,
				l.intensity * pow(r_dot_v / (VLEN(R) * VLEN(V)), s)));
		}
	}
	return (clr);
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
	return (add_compute_light(env->s.objs[i].clr, lh.p, lh.n, env->s.l,
			env->s.objs[i].spec, (Vec){-d.x, -d.y, -d.z}));
}

static inline Color	add_trace_ray(Environment *env, Vec d)
{
	fDot	t;
	bool	is_figure;
	int32_t	i;

	i = -1;
	while (env->s.ins_objs > ++i)
		if ((is_figure = add_inter(env, d, &t, i)))
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
