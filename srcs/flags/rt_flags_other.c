/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:09:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/10 11:26:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	f_nb(Environment *const env, char **av,
			size_t const ac, size_t *const av_i)
{
	(void)av;
	(void)ac;
	(void)av_i;
	return (sdl_create_window_borderless(env->sdl, WIN_X, WIN_Y, RTV1_TITLE));
}
