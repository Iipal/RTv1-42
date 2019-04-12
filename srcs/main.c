/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:07:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 20:13:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	rt_start_render(Environment *env)
{
	bool	exit_;

	exit_ = false;
	ft_putfile(RTV1_USAGE);
	env->color = (Color){0x80, 0x00, 0x40};
	printf("%d %d %d\n", env->color.r, env->color.g, env->color.b);
	sdl_clr_bright_inc(&env->color, 0.02);
	printf("%d %d %d\n", env->color.r, env->color.g, env->color.b);
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

#ifdef DEBUG

static bool	add_valid_exe_path(string path)
{
	(void)path;
	return (true);
}

#else

static bool	add_valid_exe_path(string path)
{
	ISM(E_DIR, ft_strcmp(path, RTV1_EXE_PATH), NULL, false);
	return (true);
}

#endif

int			main(int argc, string argv[])
{
	Environment	*env;

	NOTIS_F(add_valid_exe_path(*argv));
	ISARGS(argc, argv);
	ISM(E_FNLESS, ft_strlen(*argv) < ft_strlen(RTV1_FILEXT) + 1, NULL, false);
	NOTIS(E_FILEXT, !ft_strcmp(*argv
	+ (ft_strlen(*argv) - ft_strlen(RTV1_FILEXT)), RTV1_FILEXT), NULL, false);
	MEM(Environment, env, 1, E_ALLOC);
	NOTIS_F(rt_read_scene(env, *argv));
	NOTIS_F(rt_init(env));
	rt_start_render(env);
	rt_free(&env);
}
