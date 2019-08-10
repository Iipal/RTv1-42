/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsed_flags_validation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 10:35:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/10 22:18:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_errno.h"
#include "rtv1_flags.h"

void	rt_parsed_flags_validation(Flags const *const f)
{
	if (IS_BIT(g_flags, F_BIT_FRT) && !IS_BIT(g_flags, F_BIT_DBG))
		MSGN(E_USELESS_DONT(E_FRT, E_DBG));
	if (IS_BIT(g_flags, F_BIT_FTC) && !IS_BIT(g_flags, F_BIT_DBG))
		MSGN(E_USELESS_DONT(E_FTC, E_DBG));
	if (IS_BIT(g_flags, F_BIT_PU) && !IS_BIT(g_flags, F_BIT_DBG))
		MSGN(E_USELESS_DONT(E_PU, E_DBG));
	if (IS_BIT(g_flags, F_BIT_RLI) && IS_BIT(g_flags, F_BIT_NCL))
		MSGN(E_USELESS_USE(E_RLI, E_NCL));
	if (IS_BIT(g_flags, F_BIT_RLI) && !IS_BIT(g_flags, F_BIT_DBG))
		MSGN(E_USELESS_DONT(E_RLI, E_DBG));
	if (E_MAX_AL > f->ambient_light && IS_BIT(g_flags, F_BIT_NCL))
		MSGN(E_USELESS_USE(E_AL, E_NCL));
}
