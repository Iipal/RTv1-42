/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_boolean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:19:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/09 22:26:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	f_dbg(Flags *restrict const boolean_flag)
{
	if (boolean_flag->debug_mode)
		MSGN(E_REPEAT_FLAG(E_DBG));
	return (boolean_flag->debug_mode = true);
}

inline bool	f_ncl(Flags *restrict const boolean_flag)
{
	if (boolean_flag->no_calc_light)
		MSGN(E_REPEAT_FLAG(E_NCL));
	return (boolean_flag->no_calc_light = true);
}

inline bool	f_tex(Flags *restrict const boolean_flag)
{
	if (boolean_flag->textured)
		MSGN(E_REPEAT_FLAG(E_TEX));
	return (boolean_flag->textured = true);
}

inline bool	f_pu(Flags *restrict const boolean_flag)
{
	if (boolean_flag->print_usage)
		MSGN(E_REPEAT_FLAG(E_PU));
	return (boolean_flag->print_usage = true);
}

inline bool	f_rli(Flags *restrict const boolean_flag)
{
	if (boolean_flag->random_lights_intense)
		MSGN(E_REPEAT_FLAG(E_RLI));
	return (boolean_flag->random_lights_intense = true);
}
