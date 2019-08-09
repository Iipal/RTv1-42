/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:07:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 08:20:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

uint32_t	g_isr_flags = 0U;

int	main(int argc, char *argv[])
{
	Environment *env;

	NO_F(rt_valid_exe_path(*argv));
	ISARGS(argc, argv, RTV1_MAIN_USAGE);
	NO_F(rt_valid_filename(argv[argc - 1]));
	MEM(Environment, env, 1, E_ALLOC);
	rt_init_flags(&env->flags);
	env->cam_speed = MOVE_SPEED_PERCENT_DEFAULT;
	MEM(Sdl, env->sdl, 1, E_ALLOC);
	NO_F(sdl_init(env->sdl, WIN_X, WIN_Y, RTV1_TITLE));
	NODO_F(rt_parse_scene(env, argv[argc - 1]), rt_free(&env));
	NODO_F(rt_parsed_validation(&env->scene), rt_free(&env));
	NODO_F(rt_init_textures(env->scene.objs, env->scene.ins_objs,
			env->sdl->wsurf->format), rt_free(&env));
	NODO_F(rt_flags_parser(env, argv, argc - 1), rt_free(&env));
	NODO_F(rt_precalc_d(env), rt_free(&env));
	if (IS_BIT(g_flags, F_BIT_DBG))
	{
		if (IS_BIT(g_flags, F_BIT_PU))
			ft_putfile(RTV1_USAGE);
		rt_sdl_render_loop(env);
	}
	else
		rt_sdl_fake_render_loop(env);
	rt_free(&env);
}
