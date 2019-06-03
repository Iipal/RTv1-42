/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_main_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:45:06 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/03 10:45:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#ifdef DEBUG

inline bool	rt_valid_exe_path(char *const path)
{
	(void)path;
	return (true);
}

#else

inline bool	rt_valid_exe_path(char *const path)
{
	IFM_F(E_DIR, ft_strcmp(path, RTV1_EXE_PATH));
	return (true);
}

#endif

inline bool	rt_valid_filename(char *const file)
{
	NOM_F(E_FILEXT,
	!ft_strcmp(file + (ft_strlen(file) - ft_strlen(RTV1_FILEXT)), RTV1_FILEXT));
	IFM_F(E_FNMAE, ft_strlen(file) < ft_strlen(RTV1_FILEXT) + 1);
	return (true);
}
