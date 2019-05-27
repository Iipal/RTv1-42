/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_boolean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:19:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 22:42:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_fdbg(Flags *const f, strtab av,
				const size_t ac, size_t *const av_i)
{
	(void)av;
	(void)ac;
	(void)av_i;
	f->debug_mode = true;
	return (true);
}

inline bool	rt_fncl(Flags *const f, strtab av,
				const size_t ac, size_t *const av_i)
{
	(void)av;
	(void)ac;
	(void)av_i;
	f->no_calc_light = true;
	return (true);
}
