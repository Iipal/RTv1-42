/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/19 12:30:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline bool	add_inter(Environment *env, Vec d, double *t1, double *t2)
{
	const int16_t	r = env->s.sp.radius;
	const Vec		d = u_sub_vec(env->s.cam.pos, env->s.sp.pos);
	const Vec		k = {VMUL(d, d), 2.0f * VMUL(d, d), VMUL(d, d) - r * r};
	const float		disc = k.y * k.y - 4 * k.x * k.z;

	ISR(.0f > disc, false);
	*t1 = (-k.y + sqrt(disc)) / (2 * k.x);
	*t2 = (-k.y - sqrt(disc)) / (2 * k.x);
	return (true);
}

static inline Color	add_trace_ray(Environment *env, Vec d)
{
	double	t1;
	double	t2;
	bool	is_figure;

	is_figure = add_inter(env, d, &t1, &t2);
	ISR(!is_figure, ((Color){0, 0, 0}));
	if (t1 >= env->tmin && t1 <= env->tmax)
		env->closes = t1;
	if (t2 >= env->tmin && t2 <= env->tmax)
		env->closes = t2;
	return (env->s.sp.clr);
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
