/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:51:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/11 23:32:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	add_render_fps(const SDL_Surface *text,
						uiarr screen,
						const bool pos)
{
	Dot		tp;
	Dot		p;
	uiarr	pixels;

	pixels = text->pixels;
	tp.y = pos ? 20 : 0;
	p.y = -1;
	while (text->h > ++(p.y) && (p.x = -1)
	&& (tp.x = -1))
	{
		while (text->w > ++(p.x))
			screen[tp.y * WIN_X + ++(tp.x)] = pixels[p.y * text->w + p.x];
		++(tp.y);
	}
}

static void	add_fps_prepare_and_draw(const float_t dfps,
									const float_t dms,
									const Environment *env)
{
	const string	data_info[] = {" fps", " ms"};
	string			data[2];
	string			temp[2];
	SDL_Surface		*text;
	int8_t			i;

	i = -1;
	while (2 > ++i)
	{
		data[i] = (i ? ft_itoa(dms) : ft_itoa(dfps));
		temp[i] = data[i];
		data[i] = ft_strjoin(data[i], data_info[i]);
		text = sdl_optimize_font_load(data[i], (SDL_Color){127, 255, 0, 0},
			env->sdl->font, env->sdl->wsurf->format);
		ft_strdel(&(temp[i]));
		ft_strdel(&(data[i]));
		add_render_fps(text, env->sdl->pxls, i);
		SDL_FreeSurface(text);
	}
}

inline void	rt_render_fps_counter(Environment *env)
{
	static float_t	delta;
	static float_t	delta_fps;
	static float_t	delta_ms;

	(delta > REFRESH_FPS_COUNTER) ? (delta = 0) : 0;
	if (.0f == delta)
	{
		delta_fps = 1.0 / env->fps.time.res;
		delta_ms = env->fps.time.res * 1000;
	}
	add_fps_prepare_and_draw(delta_fps, delta_ms, env);
	delta += env->fps.time.res;
}

inline void	rt_fps(Fps *fps, const double_t cam_speed)
{
	fps->time.old = fps->time.current;
	fps->time.current = SDL_GetTicks();
	fps->time.res = (fps->time.current - fps->time.old) / 1000.0;
	fps->move = fps->time.res * MOVE_INC * cam_speed;
}
