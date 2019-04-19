/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/19 13:41:26 by tmaluh           ###   ########.fr       */
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

double		vec_dot(Vec v1, Vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double		vec_len(Vec v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

Color	light(Color clr, Vec P, Vec N, Light l)
{
	double			i = 0.0;
	Color			tmp;
	const			Vec L = (Vec){l.pos.x - P.x, l.pos.y - P.y, l.pos.z - P.z};
	const double	dot = vec_dot(N, L);

	tmp = clr;
	if (.0f < dot)
	{
		i += l.intensity * dot / (vec_len(N) * vec_len(L));
		clr = *sdl_clrs_add(&clr, *sdl_clr_mul(&tmp, i));
		return (clr);
	}
	return clr;
}

static inline Color	add_trace_ray(Environment *env, Vec d)
{
	double	t1;
	double	t2;
	bool	is_figure;

	is_figure = add_inter(env, d, &t1, &t2);
	ISR(!is_figure, ((Color){0, 0, 0}));
	IFDO(t1 >= env->tmin && t1 <= env->tmax, env->closes = t1);
	IFDO(t2 >= env->tmin && t2 <= env->tmax, env->closes = t2);
	Vec CD = (Vec){env->closes * d.x, env->closes * d.y, env->closes * d.z};
	Vec	P = (Vec){env->s.cam.pos.x + CD.x,
		env->s.cam.pos.y + CD.y, env->s.cam.pos.z + CD.z};
	Vec N = (Vec){P.x - env->s.sp.pos.x,
		P.y - env->s.sp.pos.y, P.z - env->s.sp.pos.z};
	N = (Vec){N.x / vec_len(N), N.y / vec_len(N), N.z / vec_len(N)};
	return (light(env->s.sp.clr, P, N, env->s.l));
}

void				rt_rendering(Environment *env)
{
	Dot		i;
	Color	curr_color;
	Vec		d;

	i.y = RT_SY;
	curr_color = (Color){0, 0, 0};
	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	while (RT_EY > ++(i.y) && (i.x = RT_SX))
	{
		while (RT_EX > ++(i.x))
		{
			d = (Vec){i.x * WIN_X / (1000.0 * WIN_X),
				i.y * WIN_Y / (1000.0 * WIN_Y), 1.0};
			curr_color = add_trace_ray(env, d);
			sdl_pixelput_canvas(env->sdl->wsurf,
				(Dot){i.x, i.y}, (Dot){WIN_X, WIN_Y}, curr_color);
		}
	}
	SDL_UpdateWindowSurface(env->sdl->w);
}
