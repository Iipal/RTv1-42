/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_main_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:45:06 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 17:44:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#ifdef DEBUG

bool	rt_valid_exe_path(char const *path)
{
	(void)path;
	return (true);
}

#else

bool	rt_valid_exe_path(char const *path)
{
	return (ft_is_one_of_n(path, 2UL, RTV1_EXE_PATH1, RTV1_EXE_PATH2));
}

#endif

bool	rt_valid_filename(char const *file)
{
	NOM_F(E_FILEXT,
	!ft_strcmp(file + (ft_strlen(file) - ft_strlen(RTV1_FILEXT)), RTV1_FILEXT));
	IFM_F(E_FNMAE, ft_strlen(file) < ft_strlen(RTV1_FILEXT) + 1);
	return (true);
}
