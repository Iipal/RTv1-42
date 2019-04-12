/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_gradient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:04:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 20:06:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

Color	*sdl_gradient(const Color *start, const Color *end, int32_t length)
{
	Color	*out;
	Color	step;
	Color	diff;
	int32_t	i;

	if (0 >= length || NULL == start || NULL == end)
		return (NULL);
	out = (Color*)malloc(sizeof(Color) * length);
	if (NULL == out)
		return (NULL);
	if (sdl_clrs_equal(start, end))
		return (SDL_memcpy(out, start, sizeof(Color) * length));
	i = -1;
	step = *start;
	diff = (Color){end->r - step.r, end->g - step.g, end->b - step.b};
	while (++i < length)
	{
		step = (Color){step.r + ((float)diff.r / length),
					step.g + ((float)diff.g / length),
					step.b + ((float)diff.b / length)};
		out[i] = step;
	}
	return (out);
}
