/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_fps_counter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 10:17:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/10 10:45:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	add_render_fps(SDL_Surface *text, uint32_t *screen, bool const pos)
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
				((uint32_t*)(text->pixels))[Y(p) * text->w + X(p)];
		++Y(tp);
	}
	SDL_FreeSurface(text);
}

static void	add_fps_prepare_and_draw(float_t const dfps, float_t const dms,
				Sdl const *const sdl, Color const *text_clr)
{
	char const	*data_info[] = {" fps", " ms"};
	char		*data[2];
	char		*temp[2];
	int8_t		i;

	i = -1;
	while (2 > ++i)
	{
		data[i] = (i ? ft_itoa(dms) : ft_itoa(dfps));
		temp[i] = data[i];
		data[i] = ft_strjoin(data[i], data_info[i]);
		add_render_fps(sdl_load_font(sdl, data[i], SDL_CLR(text_clr->c)),
			sdl->pxls, i);
		ft_strdel(&(temp[i]));
		ft_strdel(&(data[i]));
	}
}

void		rt_render_fps_counter(Color const *text_clr, Time *const fps,
				Sdl const *const sdl, double_t const frt)
{
	static float_t	delta_refresh;

	(delta_refresh < frt) ? 1 : (delta_refresh = 0.0f);
	if (.0f == delta_refresh)
	{
		fps->fps = 1.0f / fps->res;
		fps->ms = fps->res * 1000.0f;
	}
	add_fps_prepare_and_draw(fps->fps, fps->ms, sdl, text_clr);
	delta_refresh += fps->res;
}
