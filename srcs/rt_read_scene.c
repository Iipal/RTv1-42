/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:47:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/16 19:09:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	rt_scam(Environment *env, string line)
{
	double	**vars;
	int32_t	i;
	string	tmp;

	vars = (double*[]){&env->cam.pos.x, &env->cam.pos.y, &env->cam.pos.z,
						&env->cam.dir.x, &env->cam.dir.y, &env->cam.dir.z};
	tmp = line;
	line += ft_skip_to_blank(line);
	IFDOR(*line != ' ', ft_strdel(&tmp), false);
	IFDOR(!*line || !ft_isdigit(*line), ft_strdel(&tmp), false);
	i = -1;
	while (MAX_CAM_PARAMS > ++i)
	{
		line += ft_digits(*vars[i] = ft_atoi(line));
		if (MAX_CAM_PARAMS != i + 1)
		{
			if (i + 1 == MAX_CAM_PARAMS / 2)
			{
				IFDOR(*line++ != ' ', ft_strdel(&tmp), false);
			}
			else
				IFDOR(*line++ != ',', ft_strdel(&tmp), false);
		}
		else
			IFDOR(*line, ft_strdel(&tmp), 0);
	}
	ft_strdel(&tmp);
	return (true);
}

static bool	rt_clight(Environment *env, string line)
{
	if (env)
	{
	}
	ft_strdel(&line);
	return (true);
}

bool		rt_read_scene(Environment *env, string scene_file)
{
	const string			params[] = {FP_CAM, FP_LIGHT};
	const fn_scene_parse	fns[] = {rt_scam, rt_clight};
	const int32_t			fd = open(scene_file, O_RDONLY);
	int16_t					i;
	bool					is_valid;
	string					temp;

	is_valid = false;
	ISME(PERR, 0 >= fd, rt_free(&env), 0);
	while (0 < ft_gnl(fd, &temp))
	{
		i = -1;
		while (2 > ++i)
		{
			if (!ft_strncmp(temp, params[i], ft_strlen(params[i])))
				is_valid = fns[i](env, temp);
		}
		ISM(E_ISYNTAX, !is_valid, rt_free(&env), false);
	}
	close(fd);
	return (true);
}
