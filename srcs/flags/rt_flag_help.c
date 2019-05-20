/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flag_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:22:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/20 19:22:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_fhelp(Flags *const f, strtab av,
				const size_t ac, size_t *const av_i)
{
	(void)f;
	(void)ac;
	(void)av;
	(void)av_i;
	ft_putfile(RTV1_FHELP);
	exit(1);
	return (true);
}
