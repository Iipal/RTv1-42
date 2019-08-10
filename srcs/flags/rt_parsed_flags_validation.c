/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsed_flags_validation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 10:35:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/10 15:14:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_errno.h"
#include "rtv1_flags.h"

bool	rt_parsed_flags_validation(Flags const *const f)
{
	bool const			pizdec[] = {
		IS_BIT(g_flags, F_BIT_FRT) && !IS_BIT(g_flags, F_BIT_DBG),
		IS_BIT(g_flags, F_BIT_FTC) && !IS_BIT(g_flags, F_BIT_DBG),
		IS_BIT(g_flags, F_BIT_PU) && !IS_BIT(g_flags, F_BIT_DBG),
		IS_BIT(g_flags, F_BIT_RLI) && IS_BIT(g_flags, F_BIT_NCL),
		IS_BIT(g_flags, F_BIT_RLI) && !IS_BIT(g_flags, F_BIT_DBG),
		E_MAX_AL > f->ambient_light && IS_BIT(g_flags, F_BIT_NCL) };
	char const *const	pizdec_msg[] = { E_USELESS_DONT(E_FRT, E_DBG),
										E_USELESS_DONT(E_FTC, E_DBG),
										E_USELESS_DONT(E_PU, E_DBG),
										E_USELESS_USE(E_RLI, E_NCL),
										E_USELESS_DONT(E_RLI, E_DBG),
										E_USELESS_USE(E_AL, E_NCL) };
	bool				is_valid;
	size_t				i;

	i = ~0UL;
	is_valid = true;
	while (sizeof(pizdec) / sizeof(*pizdec) > ++i)
		if (pizdec[i])
		{
			MSGN(pizdec_msg[i]);
			is_valid = false;
		}
	return (is_valid);
}
