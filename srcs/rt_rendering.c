/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/19 10:23:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool		add_inter(Environment *env, Vec d, double *t1, double *t2)
{
	const Vec p = env->s.sp.pos;
	const int16_t r = env->s.sp.radius;
	const Vec dist = u_sub_vec(env->s.cam.pos, p);

	float k1 = u_mul_vec(d, d);
	float k2 = 2 * u_mul_vec(dist, d);
	float k3 = u_mul_vec(dist, dist) - r * r;

	float disc = k2 * k2 - 4 * k1 * k3;
	ISR(.0f > disc, false);
	*t1 = (-k2 + sqrt(disc)) / (2 * k1);
	*t2 = (-k2 - sqrt(disc)) / (2 * k1);
	return (true);
}

Color	add_trace_ray(Environment *env, Vec d)
{
	double		t1 = 0;
	double		t2 = 0;
	const bool	is_figure = add_inter(env, d, &t1, &t2);

	ISR(!is_figure, ((Color){0, 0, 0}));
	if (t1 >= env->tmin && t1 <= env->tmax)
		env->closes = t1;
	if (t2 >= env->tmin && t2 <= env->tmax)
		env->closes = t2;
	return (env->s.sp.clr);
}

void			rt_rendering(Environment *env)
{
	Dot		i;
	Color	curr_color;

	i.y = RT_SY;
	curr_color = (Color){0, 0, 0};
	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	while (RT_EY > ++(i.y) && (i.x = RT_SX))
	{
		while (RT_EX > ++(i.x))
		{
			Vec d = (Vec){i.x * WIN_X / (1000.0 * WIN_X),
				i.y * WIN_Y / (1000.0 * WIN_Y), 1.0};
			curr_color = add_trace_ray(env, d);
			sdl_pixelput_canvas(env->sdl->wsurf,
				(Dot){i.x, i.y}, (Dot){WIN_X, WIN_Y}, curr_color);
		}
	}
	SDL_UpdateWindowSurface(env->sdl->w);
}
