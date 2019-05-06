/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:07:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/28 22:55:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <time.h>

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
	ft_putfile(RTV1_USAGE);
	rt_render_loop(env);
	rt_free(&env);
}
