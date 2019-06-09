/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flag_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:09:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/09 22:48:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	f_nb(Environment *restrict const env, strtab av,
					const size_t ac, size_t *const av_i)
{
	(void)av; (void)ac; (void)av_i;
	return (sdl_create_window_without_borders(env->sdl,
		WIN_X, WIN_Y, RTV1_TITLE));
}
