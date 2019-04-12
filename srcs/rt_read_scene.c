/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:47:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 11:33:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_check_win_sizes(Environment *env, string win_info)
{
	int8_t		i;
	const char	params[2] = {'w', 'h'};
	int32_t		**sizes;
	string		itmp;

	i = -1;
	itmp = win_info;
	sizes = (int32_t*[]){&env->w_size.x, &env->w_size.y};
	while (2 > ++i)
	{
		if (params[i] == *win_info++ && ':' == *win_info++)
			win_info += ft_skip_blanks(win_info);
		ISM(E_WINSIZE, WIN_MIN_X > (*sizes[i] = ft_atoi(win_info))
			|| WIN_MAX_X < *sizes[i], ft_strdel(&itmp), false);
		IFDO(*win_info, win_info += ft_digits(*sizes[i]));
		if (!i)
		{
			ISM(E_ISYNTAX, !ft_skip_blanks(win_info), ft_strdel(&itmp), false);
			win_info += ft_skip_blanks(win_info);
			ISM(E_ISYNTAX, !*win_info, ft_strdel(&itmp), false);
		}
	}
	ISM(E_ISYNTAX, *win_info++ != ';' || *win_info, ft_strdel(&itmp), 0);
	ft_strdel(&itmp);
	return (true);
}

bool		rt_read_scene(Environment *env, string scene_file)
{
	const int32_t	fd = open(scene_file, O_RDONLY);
	string			temp;

	ISM(E_FILE, 0 >= fd, rt_free(&env), 0);
	ISM(E_FEMPTY, 0 >= ft_gnl(fd, &temp), rt_free(&env), false);
	IFDOR(!add_check_win_sizes(env, temp), rt_free(&env), false);
	while (0 < ft_gnl(fd, &temp))
	{
		if (*temp)
		{
			printf("%s\n", temp);
		}
		ft_strdel(&temp);
	}
	close(fd);
	return (true);
}
