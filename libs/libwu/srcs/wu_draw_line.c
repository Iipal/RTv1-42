/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:00:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 17:43:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "libftsdl.h"

#include "wu_algo.h"
#include "wu_algo_utils.h"

static void
s_draw_line(const bool steep,
			const double_t gradient,
			double_t intery,
			const s2df pxl1,
			const s2df pxl2,
			SDL_Surface *restrict surf)
{
	for (size_t i = pxl1.x + 1; i < pxl2.x - 1; i++) {
		if (steep) {
			putpxl_plot(u_ipart(intery), i, u_rfpart(intery), surf,
				(Color){0xffffff});
			putpxl_plot(u_ipart(intery) + 1, i, u_fpart(intery), surf,
				(Color){0xffffff});
		} else {
			putpxl_plot(i, u_ipart(intery), u_rfpart(intery), surf,
				(Color){0xffffff});
			putpxl_plot(i, u_ipart(intery) + 1, u_fpart(intery), surf,
				(Color){0xffffff});
		}
		intery += gradient;
	}
}

static __wu_always_inline s2df
s_calc_endpoint(const s2df xy,
				const double_t gradient,
				const bool steep,
				SDL_Surface *restrict surf)
{
	const double_t	xgap = u_rfpart(xy.x + 0.5);
	const s2df	end = { u_round(xy.x),
		xy.y + gradient * (u_round(xy.x) - xy.x) };
	const s2df	pxl = {end.x, u_ipart(end.y)};

	if (steep) {
		putpxl_plot(pxl.y , pxl.x, u_rfpart(end.y) * xgap, surf,
			(Color){0xffffff});
		putpxl_plot(pxl.y + 1, pxl.x, u_fpart(end.y) * xgap, surf,
			(Color){0xffffff});
	} else {
		putpxl_plot(pxl.x, pxl.y, u_rfpart(end.y) * xgap, surf,
			(Color){0xffffff});
		putpxl_plot(pxl.x, pxl.x + 1, u_fpart(end.y) * xgap, surf,
			(Color){0xffffff});
	}
	return pxl;
}

void
wu_draw_line(s2df xy0, s2df xy1, SDL_Surface *restrict surf)
{
	const bool	steep = fabs(xy1.y - xy0.y) > fabs(xy1.x - xy0.x);
	double_t	gradient;

	if (steep) {
		ft_swap(&xy0.x, &xy0.y);
		ft_swap(&xy1.x, &xy1.y);
	}
	if (xy0.x > xy1.x) {
		ft_swap(&xy0.x, &xy1.x);
		ft_swap(&xy0.y, &xy1.y);
	}
	{
		s2df const	d = {xy1.x - xy0.x, xy1.y - xy0.y};
		gradient = d.y / d.x;
		if (0.0 == d.x)
			gradient = 1.0;
	}
	s_draw_line(steep, gradient,
		(xy0.y + gradient * (u_round(xy0.x) - xy0.x)) + gradient,
		s_calc_endpoint(xy0, gradient, steep, surf),
		s_calc_endpoint(xy1, gradient, steep, surf), surf);
}
