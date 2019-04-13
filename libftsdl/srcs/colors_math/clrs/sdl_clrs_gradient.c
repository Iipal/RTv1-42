/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_gradient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:04:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/13 19:35:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl_colors_math.h"

Color	*sdl_clrs_gradient(const Color start, const Color end, int32_t len)
{
	Color	*out;
	FColor	step;
	FColor	diff;
	int32_t	i;

	IFDOR(1 >= len, NULL, NULL);
	IFDOR(NULL == (out = (Color*)malloc(sizeof(Color) * len)), NULL, NULL);
	i = 0;
	*out = start;
	if (sdl_clrs_equal(start, end))
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
