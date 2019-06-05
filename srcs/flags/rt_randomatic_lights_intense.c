/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_randomatic_lights_intense.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:48:43 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/05 23:51:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			rt_randomatic_lights_intense(Light *restrict const lights,
											const size_t ins_lights)
{
	size_t	i;

	i = ~0L;
	while (ins_lights > ++i)
		lights[i].intens = (ft_rand(100) + 1) / 100.0 - 0.01;
}
