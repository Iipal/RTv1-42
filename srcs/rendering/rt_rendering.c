/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:11:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/20 12:20:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_rendering(Environment *env)
{
	SDL_FillRect(env->sdl->wsurf, NULL, RGB_BLACK);
	IFDO(env->s.ins_objs, rt_raytracing(env));
	IFDO(env->isr.is_render_fps, rt_render_fps_counter(env));
	SDL_UpdateWindowSurface(env->sdl->w);
}