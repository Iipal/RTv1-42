/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:07:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 15:53:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	rt_start_render(Env *env)
{
	bool	exit_;

	exit_ = false;
	while (!exit_)
		while (SDL_PollEvent(&env->sdl->e) > 0)
			if (env->sdl->e.type == SDL_QUIT)
				exit_ = true;
}

int			main(int argc, char *argv[])
{
	Env	*env;

	ISM(E_DIR, ft_strcmp(*argv, RTV1_EXE_PATH), exit(EXIT_FAILURE), 0);
	MEM(Env, env, 1, E_ALLOC);
	ISARGS(argc, argv);
	NOTIS_F(rt_init(env));
	rt_start_render(env);
	rt_free(&env);
}
