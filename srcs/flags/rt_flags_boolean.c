/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_boolean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:19:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/09 13:58:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_fdbg(Flags *restrict const boolean_flag)
{
	return (boolean_flag->debug_mode = true);
}

inline bool	rt_fncl(Flags *restrict const boolean_flag)
{
	return (boolean_flag->no_calc_light = true);
}

inline bool	rt_ftex(Flags *restrict const boolean_flag)
{
	return (boolean_flag->textured = true);
}

inline bool	rt_fpu(Flags *restrict const boolean_flag)
{
	return (boolean_flag->print_usage = true);
}

inline bool	rt_frli(Flags *restrict const boolean_flag)
{
	return (boolean_flag->random_lights_intense = true);
}
