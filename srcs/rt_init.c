/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/11 11:59:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_init(Enviroment *env)
{
	ISM(SDL_GetError(), SDL_Init(SDL_INIT_EVERYTHING) < 0, exit(1), false);
	MEM(Sdl, env->sdl, 1, E_ALLOC);
	NOTIS(SDL_GetError(),
		env->sdl->win = SDL_CreateWindow(RTV1_TITLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, env->w_size.x, env->w_size.y, 4), exit(1), 0);
	NOTIS(SDL_GetError(),
	env->sdl->win_surf = SDL_GetWindowSurface(env->sdl->win), rt_free(&env), 0);
	NOTIS(E_SURFPXL, env->sdl->pixels = env->sdl->win_surf->pixels, exit(1), 0);
	return (true);
}
