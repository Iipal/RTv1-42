/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_is_flags_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 14:32:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/13 16:04:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_flags.h"

inline size_t	rt_is_flag_boolean(string flag)
{
	size_t	out;

	out = 0;
	if ('-' == *flag && '-' != *(flag + 1))
		out = ft_is_one_of_str(flag, false, MAX_BOOLEAN_FLAGS,
			SF_DBG, SF_NCL, SF_TEX, SF_RLI, SF_PU);
	else if ('-' == *flag && '-' == *(flag + 1))
		out = ft_is_one_of_str(flag, false, MAX_BOOLEAN_FLAGS,
			F_DBG, F_NCL, F_TEX, F_RLI, F_PU);
	return (out);
}

inline size_t	rt_is_flag_wparam(string flag)
{
	size_t	out;

	out = 0;
	if ('-' == *flag && '-' != *(flag + 1))
		out = ft_is_one_of_str(flag, false, MAX_WPARAMS_FLAGS,
			SF_VPS, SF_AL, SF_FTC, SF_FRT, SF_AA);
	else if ('-' == *flag && '-' == *(flag + 1))
		out = ft_is_one_of_str(flag, false, MAX_WPARAMS_FLAGS,
			F_VPS, F_AL, F_FTC, F_FRT, F_AA);
	return (out);
}

inline size_t	rt_is_flag_other(string flag)
{
	size_t	out;

	out = 0;
	if ('-' == *flag && '-' != *(flag + 1))
		out = ft_is_one_of_str(flag, false, MAX_OTHER_FLAGS, SF_NB);
	else if ('-' == *flag && '-' == *(flag + 1))
		out = ft_is_one_of_str(flag, false, MAX_OTHER_FLAGS, F_NB);
	return (out);
}
