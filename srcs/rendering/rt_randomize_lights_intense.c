/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_randomize_lights_intense.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:48:43 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 09:12:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			rt_randomize_lights_intense(Light *restrict const lights,
					size_t const ins_lights, float_t const time)
{
	static float_t	delta_refresh;
	size_t			i;

	i = ~0UL;
	(delta_refresh < .25f) ? 1 : (delta_refresh = 0.0f);
	if (.0f == delta_refresh)
		while (ins_lights > ++i)
			lights[i].intens = (ft_rand(100) + 1) / 100.0f - 0.01f;
	delta_refresh += time;
}
