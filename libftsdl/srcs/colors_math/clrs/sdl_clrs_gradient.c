/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_clrs_gradient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:04:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 20:28:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

Color	*sdl_clrs_gradient(const Color *start, const Color *end, int32_t len)
{
	Color	*out;
	Color	step;
	Color	diff;
	int32_t	i;

	if (0 >= len || NULL == start || NULL == end)
		return (NULL);
	out = (Color*)malloc(sizeof(Color) * len);
	if (NULL == out)
		return (NULL);
	if (sdl_clrs_equal(start, end))
		return (SDL_memcpy(out, start, sizeof(Color) * len));
	i = -1;
	step = *start;
	diff = (Color){end->r - step.r, end->g - step.g, end->b - step.b};
	while (++i < len)
	{
		step = (Color){step.r + ((float)diff.r / len),
					step.g + ((float)diff.g / len),
					step.b + ((float)diff.b / len)};
		out[i] = step;
	}
	return (out);
}
