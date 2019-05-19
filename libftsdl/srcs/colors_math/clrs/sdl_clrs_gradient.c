/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_gradient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:04:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/19 11:24:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

Color	*sdl_clrs_gradient(Color start,
					const Color end,
					const size_t len)
{
	Color	*out;
	FColor	step;
	FColor	diff;
	size_t	i;

	i = ~0L;
	IFR(1 > len, NULL);
	NO_R(out = (Color*)malloc(sizeof(Color) * len), NULL);
	if (SDL_CLRS_CMP(start.c, end.c) || 1 == len)
	{
		while (len > ++i)
			out[i] = start;
		return (out);
	}
	*out = start;
	step = (FColor){start.c.r, start.c.g, start.c.b};
	diff = (FColor){(end.c.r - step.r) / ((float_t)len - 1.0f),
					(end.c.g - step.g) / ((float_t)len - 1.0f),
					(end.c.b - step.b) / ((float_t)len - 1.0f)};
	while (len > ++i)
	{
		step = (FColor){step.r + diff.r, step.g + diff.g, step.b + diff.b};
		out[i].c = (t_clr){INRANGE(step.r), INRANGE(step.g), INRANGE(step.b)};
	}
	return (out);
}
