/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:07:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/22 16:01:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <time.h>

#ifdef DEBUG

static inline bool	add_valid_exe_path(char *const path)
{
	(void)path;
	return (true);
}

#else

static inline bool	add_valid_exe_path(char *const path)
{
	IFM_F(E_DIR, ft_strcmp(path, RTV1_EXE_PATH));
	return (true);
}

#endif

static inline bool	add_valid_filename(char *const file)
{
	NOM_F(E_FILEXT,
	!ft_strcmp(file + (ft_strlen(file) - ft_strlen(RTV1_FILEXT)), RTV1_FILEXT));
	IFM_F(E_FNMAE, ft_strlen(file) < ft_strlen(RTV1_FILEXT) + 1);
	return (true);
}

static void			add_fake_render_loop(Environment *const env)
{
	bool	quit;

	quit = false;
	rt_rendering(env);
	while (!quit)
		while (SDL_PollEvent(&env->sdl->e) > 0)
			if (SDL_QUIT == env->sdl->e.type)
				quit = true;
			else if (SDL_KEYDOWN == env->sdl->e.type && SDLK_ESCAPE == SEKEY)
				quit = true;
}

int					main(int argc, string argv[])
{
	Environment *env;

	NO_F(add_valid_exe_path(*argv));
	ISARGS(argc, argv);
	NO_F(add_valid_filename(argv[argc - 1]));
	MEM(Environment, env, 1, E_ALLOC);
	NO_F(rt_read_scene(env, argv[argc - 1]));
	NO_F(rt_init(env));
	NODO_F(rt_flags_parser(&env->flags, argv, argc - 1), rt_free(&env));
	if (env->flags.debug_mode)
	{
		ft_putfile(RTV1_USAGE);
		rt_render_loop(env);
	}
	else
		add_fake_render_loop(env);
	rt_free(&env);
}
