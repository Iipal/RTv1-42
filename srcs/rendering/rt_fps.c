/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:51:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/07 19:26:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_fps(Fps *restrict const fps, const double_t cam_speed)
{
	fps->time.old = fps->time.current;
	fps->time.current = SDL_GetTicks();
	fps->time.res = (fps->time.current - fps->time.old) / 1000.0f;
	fps->move = fps->time.res * MOVE_INC * cam_speed;
	fps->l_move = fps->move * 5.0f;
	fps->l_intens = fps->move / 5.0f;
	fps->o_spec_intens = fps->move * 100.0f;
}

static void	add_render_fps(SDL_Surface *text,
						uint32_t *const screen,
						const bool pos)
{
	__v2si	tp;
	__v2si	p;

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
									const Environment *const env)
{
	const string	data_info[] = {" fps", " ms"};
	SDL_Surface		*text;
	string			data[2];
	string			temp[2];
	int8_t			i;

	i = -1;
	while (2 > ++i)
	{
		data[i] = (i ? ft_itoa(dms) : ft_itoa(dfps));
		temp[i] = data[i];
		data[i] = ft_strjoin(data[i], data_info[i]);
		text = sdl_load_font(env->sdl, data[i],
			SDL_CLR(env->flags.fps_text_color.c), text);
		add_render_fps(text, env->sdl->pxls, i);
		ft_strdel(&(temp[i]));
		ft_strdel(&(data[i]));
	}
}

inline void	rt_render_fps_counter(Environment *const env)
{
	static float_t	delta_refresh;

	(delta_refresh < env->flags.fps_refresh_timer) ? 1 : (delta_refresh = 0);
	if (.0f == delta_refresh)
	{
		env->fps.time.fps = 1.0f / env->fps.time.res;
		env->fps.time.ms = env->fps.time.res * 1000.0f;
	}
	add_fps_prepare_and_draw(env->fps.time.fps, env->fps.time.ms, env);
	delta_refresh += env->fps.time.res;
}
