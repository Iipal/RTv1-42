/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:47:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/11 16:48:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_check_win_sizes(Enviroment *env, string win_info)
{
	int8_t		i;
	const char	params[2] = {'w', 'h'};
	int32_t		**sizes;
	string		temp_info;

	i = -1;
	temp_info = win_info;
	sizes = (int32_t*[]){&env->w_size.x, &env->w_size.y};
	while (2 > ++i)
	{
		if (params[i] == *win_info++ && ':' == *win_info++)
			win_info += ft_skip_blanks(win_info);
		ISM(E_WINSIZE, WIN_MIN_X > (*sizes[i] = ft_atoi(win_info))
			|| WIN_MAX_X < *sizes[i], ft_strdel(&temp_info), false);
		IFDO(*win_info, win_info += ft_digits(*sizes[i]));
		if (!i)
		{
			win_info += ft_skip_blanks(win_info);
			ISM(E_ISYNTAX, !*win_info, ft_strdel(&temp_info), false);
		}
	}
	ISM(E_ISYNTAX, *win_info++ != ';' || *win_info, ft_strdel(&temp_info), 0);
	ft_strdel(&temp_info);
	return (true);
}

bool		rt_read_scene(Enviroment *env, string scene_file)
{
	const int32_t	fd = open(scene_file, O_RDONLY);
	string			temp;

	ISM(E_FILE, 0 >= fd, rt_free(&env), 0);
	ISM(E_FREAD, 0 >= ft_gnl(fd, &temp), rt_free(&env), false);
	IFDOR(!add_check_win_sizes(env, temp), rt_free(&env), false);
	close(fd);
	return (true);
}
