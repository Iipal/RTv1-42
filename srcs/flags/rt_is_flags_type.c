/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_is_flags_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 14:32:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/19 13:41:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

size_t	rt_is_flag_boolean(char const *flag)
{
	size_t	out;

	out = 0UL;
	if ('-' == *flag && '-' != *(flag + 1))
		out = ft_is_one_of_str(flag, MAX_BOOLEAN_FLAGS,
			SF_DBG, SF_NCL, SF_TEX, SF_RLI, SF_PU);
	else if ('-' == *flag && '-' == *(flag + 1))
		out = ft_is_one_of_str(flag, MAX_BOOLEAN_FLAGS,
			F_DBG, F_NCL, F_TEX, F_RLI, F_PU);
	return (out);
}

size_t	rt_is_flag_wparam(char const *flag)
{
	size_t	out;

	out = 0UL;
	if ('-' == *flag && '-' != *(flag + 1))
		out = ft_is_one_of_str(flag, MAX_WPARAMS_FLAGS,
			SF_VPS, SF_AL, SF_FTC, SF_FRT, SF_AA);
	else if ('-' == *flag && '-' == *(flag + 1))
		out = ft_is_one_of_str(flag, MAX_WPARAMS_FLAGS,
			F_VPS, F_AL, F_FTC, F_FRT, F_AA);
	return (out);
}

size_t	rt_is_flag_other(char const *flag)
{
	size_t	out;

	out = 0UL;
	if ('-' == *flag && '-' != *(flag + 1))
		out = ft_is_one_of_str(flag, MAX_OTHER_FLAGS, SF_NB);
	else if ('-' == *flag && '-' == *(flag + 1))
		out = ft_is_one_of_str(flag, MAX_OTHER_FLAGS, F_NB);
	return (out);
}
