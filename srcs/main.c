/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:07:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 20:15:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	rt_start_render(Enviroment *env)
{
	bool	exit_;

	exit_ = false;
	while (!exit_)
	{
		while (SDL_PollEvent(&env->sdl->e) > 0)
			if (env->sdl->e.type == SDL_QUIT)
				exit_ = true;
			else if (env->sdl->e.type == SDL_KEYDOWN
			&& env->sdl->e.key.keysym.sym == SDLK_ESCAPE)
				exit_ = true;
		rt_rendering(env);
	}
}

int			main(int argc, char *argv[])
{
	Enviroment	*env;

	ISM(E_DIR, ft_strcmp(*argv, RTV1_EXE_PATH), exit(EXIT_FAILURE), false);
	ISARGS(argc, argv);
	ISM(E_FNLESS, ft_strlen(*argv) < ft_strlen(RTV1_FILEXT) + 1, (void)env, 0);
	NOTIS(E_FILEXT, !ft_strcmp(*argv
	+ (ft_strlen(*argv) - ft_strlen(RTV1_FILEXT)), RTV1_FILEXT), (void)env, 0);
	MEM(Enviroment, env, 1, E_ALLOC);
	NOTIS_F(rt_read_scene(env, *argv));
	NOTIS_F(rt_init(env));
	rt_start_render(env);
	rt_free(&env);
}
