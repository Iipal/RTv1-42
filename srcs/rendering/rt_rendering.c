/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 19:01:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_rendering(Environment *env)
{
	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	rt_raytracing(env);
	IFDO(env->isr.is_render_fps, rt_render_fps_counter(env));
	SDL_UpdateWindowSurface(env->sdl->w);
}
