/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_boolean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:19:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/08 22:39:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	f_dbg(void)
{
	if (IS_BIT(g_flags, F_BIT_DBG))
		MSGN(E_REPEAT_FLAG(E_DBG));
	else
		SET_BIT(g_flags, F_BIT_DBG);
	return (true);
}

bool	f_ncl(void)
{
	if (IS_BIT(g_flags, F_BIT_NCL))
		MSGN(E_REPEAT_FLAG(E_NCL));
	else
		SET_BIT(g_flags, F_BIT_NCL);
	return (true);
}

bool	f_tex(void)
{
	if (IS_BIT(g_flags, F_BIT_TEX))
		MSGN(E_REPEAT_FLAG(E_TEX));
	else
		SET_BIT(g_flags, F_BIT_TEX);
	return (true);
}

bool	f_pu(void)
{
	if (IS_BIT(g_flags, F_BIT_PU))
		MSGN(E_REPEAT_FLAG(E_PU));
	else
		SET_BIT(g_flags, F_BIT_PU);
	return (true);
}

bool	f_rli(void)
{
	if (IS_BIT(g_flags, F_BIT_RLI))
		MSGN(E_REPEAT_FLAG(E_RLI));
	else
		SET_BIT(g_flags, F_BIT_RLI);
	return (true);
}
