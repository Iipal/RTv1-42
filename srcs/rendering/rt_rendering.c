/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 20:03:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_rendering(Environment *env)
{
	Dot	i;

	i.y = RT_CANVAS_STARTY;
	while (RT_CANVAS_ENDY > ++(i.y) && (i.x = RT_CANVAS_STARTX))
		while (RT_CANVAS_ENDX > ++(i.x))
			rt_raytracing(env, i);
	IFDO(env->isr.is_render_fps, rt_render_fps_counter(env));
}
