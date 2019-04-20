/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:23:36 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/20 11:52:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline bool	add_inter(Environment *env, Vec d, double *t1, double *t2)
{
	const int16_t	r = env->s.sp.radius;
	const Vec		ds = u_sub_vec(env->s.cam.pos, env->s.sp.pos);
	const Vec		k = {VMUL(d, d), 2.0f * VMUL(ds, d), VMUL(ds, ds) - r * r};
	const float		disc = k.y * k.y - 4 * k.x * k.z;

	ISR(.0f > disc, false);
	*t1 = (-k.y + sqrt(disc)) / (2 * k.x);
	*t2 = (-k.y - sqrt(disc)) / (2 * k.x);
	return (true);
}

static inline Color	light(Color clr, Vec p, Vec n, Light l)
{
	double			i;
	Color			tmp;
	const Vec		x = (Vec){l.pos.x - p.x, l.pos.y - p.y, l.pos.z - p.z};
	const double	dot = VDOT(n, x);

	tmp = clr;
	i = 0.0;
	if (.0f < dot)
	{
		i += l.intensity * dot / (VLEN(n) * VLEN(x));
		clr = *sdl_clrs_add(&clr, *sdl_clr_mul(&tmp, i));
	}
	return (clr);
}

static inline Color	add_trace_ray(Environment *env, Vec d)
{
	double	t1;
	double	t2;
	bool	is_figure;
	t_lhelp	lh;

	is_figure = add_inter(env, d, &t1, &t2);
	ISR(!is_figure, ((Color){0, 0, 0}));
	IFDO(t1 >= TMIN && t1 <= TMAX, env->s.cobj = t1);
	IFDO(t2 >= TMIN && t2 <= TMAX, env->s.cobj = t2);
	lh.cd = (Vec){env->s.cobj * d.x, env->s.cobj * d.y, env->s.cobj * d.z};
	lh.p = (Vec){env->s.cam.pos.x + lh.cd.x,
		env->s.cam.pos.y + lh.cd.y, env->s.cam.pos.z + lh.cd.z};
	lh.n = (Vec){lh.p.x - env->s.sp.pos.x,
		lh.p.y - env->s.sp.pos.y, lh.p.z - env->s.sp.pos.z};
	lh.n = (Vec){lh.n.x / VLEN(lh.n), lh.n.y / VLEN(lh.n), lh.n.z / VLEN(lh.n)};
	return (light(env->s.sp.clr, lh.p, lh.n, env->s.l));
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
