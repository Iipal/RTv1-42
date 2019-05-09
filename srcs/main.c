/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:07:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/09 11:30:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <time.h>

#ifdef DEBUG

static inline bool	add_valid_exe_path(string path)
{
	(void)path;
	return (true);
}

#else

static inline bool	add_valid_exe_path(string path)
{
	ISM(E_DIR, ft_strcmp(path, RTV1_EXE_PATH), NULL, false);
	return (true);
}

#endif

static inline bool	add_valid_filename(string file)
{
	ISM(E_FNMAE, ft_strlen(file) < ft_strlen(RTV1_FILEXT) + 1, NULL, false);
	NOTIS(E_FILEXT,
		!ft_strcmp(file + (ft_strlen(file) - ft_strlen(RTV1_FILEXT)),
		RTV1_FILEXT), NULL, false);
	return (true);
}

int					main(int argc, string argv[])
{
	Environment	*env;

	NOTIS_F(add_valid_exe_path(*argv));
	ISARGS(argc, argv);
	NOTIS_F(add_valid_filename(*argv));
	MEM(Environment, env, 1, E_ALLOC);
	NOTIS_F(rt_read_scene(env, *argv));
	NOTIS_F(rt_init(env));
	ft_putfile(RTV1_USAGE);
	rt_render_loop(env);
	rt_free(&env);
}
