/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_fps_counter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 10:17:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/11 13:50:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	s_render_strinfo(SDL_Surface *text,
				SDL_Surface *const screen,
				int32_t const y_pos)
{
	int32_t	*const src = text->pixels;
	int32_t	*const dst = screen->pixels;
	int32_t	i;

	i = -1;
	while (text->h > ++i)
		ft_memcpy(dst + (screen->w * (i + y_pos)),
			src + (text->w * i), sizeof(int32_t) * text->w);
	SDL_FreeSurface(text);
}

static void	s_prepare_strinfo(char *const dst,
				float_t const info,
				char str_info[])
{
	char	*temp;

	temp = ft_itoa(info);
	ft_bzero(dst, sizeof(char) * FPS_MAX_BUFF_SIZE);
	ft_strcpy(dst, str_info);
	ft_strcpy(dst + ft_strlen(str_info), temp);
	ft_strdel(&temp);
}

void		rt_render_fps_counter(Color const *text_clr,
				Time *const fps,
				Sdl const *const sdl,
				double_t const frt,
				FpsRenderHelper *const frh)
{
	(frh->frt_delta < frt) ? 1 : (frh->frt_delta = 0.0f);
	if (.0f == frh->frt_delta)
	{
		frh->fps = 1.0f / fps->res;
		frh->ms = fps->res * 1000.0f;
	}
	s_prepare_strinfo(frh->fps_str, frh->fps, "fps: ");
	s_prepare_strinfo(frh->ms_str, frh->ms, "ms: ");
	s_render_strinfo(sdl_load_font(sdl, frh->fps_str,
		SDL_CLR(text_clr->c)), sdl->wsurf, 0);
	s_render_strinfo(sdl_load_font(sdl, frh->ms_str,
		SDL_CLR(text_clr->c)), sdl->wsurf, FPS_FONT_SIZE);
	frh->frt_delta += fps->res;
}
