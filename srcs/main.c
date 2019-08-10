/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:07:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/11 01:05:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			main(int argc, char *argv[])
{
	Environment *env;

	NO_F(rt_valid_exe_path(*argv));
	ISARGS(argc, argv, RTV1_MAIN_USAGE);
	NO_F(rt_valid_filename(argv[argc - 1]));
	MEM(Environment, env, 1, E_ALLOC);
	NODO_F(rt_main_env_init(env), rt_free(&env));
	NODO_F(rt_parse_scene(env, argv[argc - 1]), rt_free(&env));
	NODO_F(rt_parsed_scene_validation(&env->scene), rt_free(&env));
	NODO_F(rt_parse_flags(env, argv, argc - 1), rt_free(&env));
	rt_parsed_flags_validation(&env->flags);
	NODO_F(rt_init_textures(env->scene.objs, env->scene.ins_objs,
			env->sdl->wsurf->format), rt_free(&env));
	NODO_F(rt_precalc_d(env), rt_free(&env));
	if (IS_BIT(g_flags, F_BIT_DBG))
	{
		NODO_F(env->frh = rt_init_fps_render_helper(), rt_free(&env));
		if (IS_BIT(g_flags, F_BIT_PU))
			ft_putfile(RTV1_USAGE);
		rt_sdl_render_loop(env);
	}
	else
		rt_sdl_fake_render_loop(env);
	rt_free(&env);
}
