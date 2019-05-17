/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:51:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 12:48:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	add_render_fps(SDL_Surface *text,
						uiarr screen,
						const bool pos)
{
	Dot		tp;
	Dot		p;

	Y(p) = -1;
	Y(tp) = pos ? 20 : 0;
	while (text->h > ++Y(p) && (X(p) = -1)
							&& (X(tp) = -1))
	{
		while (text->w > ++X(p))
			screen[Y(tp) * WIN_X + ++X(tp)] =
				((uiarr)(text->pixels))[Y(p) * text->w + X(p)];
		++Y(tp);
	}
	SDL_FreeSurface(text);
}

static void	add_fps_prepare_and_draw(const float_t dfps,
									const float_t dms,
									const Environment *env)
{
	const string	data_info[] = {" fps", " ms"};
	string			data[2];
	string			temp[2];
	int8_t			i;

	i = -1;
	while (2 > ++i)
	{
		data[i] = (i ? ft_itoa(dms) : ft_itoa(dfps));
		temp[i] = data[i];
		data[i] = ft_strjoin(data[i], data_info[i]);
		add_render_fps(sdl_optimize_font_load(env->sdl->font, data[i],
			SDL_HEX_TO_CLR(env->flags.fps_text_color), env->sdl->wsurf->format),
			env->sdl->pxls, i);
		ft_strdel(&(temp[i]));
		ft_strdel(&(data[i]));
	}
}

inline void	rt_render_fps_counter(Environment *env)
{
	static float_t	delta;

	(delta > REFRESH_FPS_COUNTER) ? (delta = 0) : 0;
	if (.0f == delta)
	{
		env->fps.time.fps = 1.0 / env->fps.time.res;
		env->fps.time.ms = env->fps.time.res * 1000;
	}
	add_fps_prepare_and_draw(env->fps.time.fps, env->fps.time.ms, env);
	delta += env->fps.time.res;
}

inline void	rt_fps(Fps *fps, const double_t cam_speed)
{
	fps->time.old = fps->time.current;
	fps->time.current = SDL_GetTicks();
	fps->time.res = (fps->time.current - fps->time.old) / 1000.0;
	fps->move = fps->time.res * MOVE_INC * cam_speed;
}
