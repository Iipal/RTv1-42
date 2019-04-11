/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:47:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/11 11:56:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_check_win_sizes(Enviroment *env, string win_info)
{
	string	temp_info;

	temp_info = win_info;
	if (*win_info++ == 'w' && *win_info++ == ':')
		win_info += ft_skip_blanks(win_info);
	ISM(E_WINSIZE, 0 >= (env->w_size.x = ft_atoi(win_info))
		|| WIN_MAX_X < env->w_size.x, ft_strdel(&temp_info), false);
	win_info += ft_digits(env->w_size.x);
	win_info += ft_skip_blanks(win_info);
	ISM(E_ISYNTAX, !*win_info, ft_strdel(&temp_info), false);
	if (*win_info++ == 'h' && *win_info++ == ':')
		win_info += ft_skip_blanks(win_info);
	ISM(E_WINSIZE, 0 >= (env->w_size.y = ft_atoi(win_info))
		|| WIN_MAX_X < env->w_size.y, ft_strdel(&temp_info), false);
	win_info += ft_digits(env->w_size.y);
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
