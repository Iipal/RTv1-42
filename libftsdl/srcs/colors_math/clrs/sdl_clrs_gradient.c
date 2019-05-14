/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_gradient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:04:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 10:19:41 by tmaluh           ###   ########.fr       */
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
	*out = start;
	if (SDL_CLRS_CMP(start, end) || 1 == len)
	{
		while (len > ++i)
			out[i] = start;
		return (out);
	}
	step = (FColor){start.r, start.g, start.b};
	diff = (FColor){(end.r - step.r) / ((float)len - 1.0f),
					(end.g - step.g) / ((float)len - 1.0f),
					(end.b - step.b) / ((float)len - 1.0f)};
	while (len > ++i)
	{
		step = (FColor){step.r + diff.r, step.g + diff.g, step.b + diff.b};
		out[i] = (Color){INRANGE(step.r), INRANGE(step.g), INRANGE(step.b)};
	}
	return (out);
}
