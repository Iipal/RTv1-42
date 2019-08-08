/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:35:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/08 22:52:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	add_valid_parsed_flags(Flags const *restrict const f)
{
	if (IS_BIT(g_flags, F_BIT_FRT) && !IS_BIT(g_flags, F_BIT_DBG))
		MSGN(E_USLSS_DONT(E_FRT, E_DBG));
	if (IS_BIT(g_flags, F_BIT_FTC) && !IS_BIT(g_flags, F_BIT_DBG))
		MSGN(E_USLSS_DONT(E_FTC, E_DBG));
	if (IS_BIT(g_flags, F_BIT_PU) && !IS_BIT(g_flags, F_BIT_DBG))
		MSGN(E_USLSS_DONT(E_PU, E_DBG));
	if (IS_BIT(g_flags, F_BIT_RLI) && IS_BIT(g_flags, F_BIT_NCL))
		MSGN(E_USLSS_USE(E_RLI, E_NCL));
	if (IS_BIT(g_flags, F_BIT_RLI) && !IS_BIT(g_flags, F_BIT_DBG))
		MSGN(E_USLSS_DONT(E_RLI, E_DBG));
	if (E_MAX_AL > f->ambient_light && IS_BIT(g_flags, F_BIT_NCL))
		MSGN(E_USLSS_USE(E_AL, E_NCL));
}

static bool	add_curr_fparse(Environment *restrict const env,
				char **av, const size_t ac, size_t *const av_i)
{
	t_fbool const	fbool[] = {f_dbg, f_ncl, f_tex, f_rli, f_pu};
	t_fwparam const	fwparam[] = {f_vps, f_al, f_ftc, f_frt, f_aa};
	t_fother const	fother[] = {f_nb};
	size_t			fn_num;

	if (ft_is_one_of_str(av[*av_i], false, 2UL, SF_HELP, F_HELP))
	{
		ft_putfile(RTV1_FUSAGE);
		return (false);
	}
	else if ((fn_num = rt_is_flag_boolean(av[*av_i])))
		return (fbool[fn_num - 1]());
	else if ((fn_num = rt_is_flag_wparam(av[*av_i])))
		return (fwparam[fn_num - 1](&env->flags, av, ac, av_i));
	else if ((fn_num = rt_is_flag_other(av[*av_i])))
		return (fother[fn_num - 1](env, av, ac, av_i));
	ERRIN(E_INVALID_FLAG, av[*av_i]);
	return (false);
}

bool		rt_flags_parser(Environment *restrict const env,
				char **av, const size_t ac)
{
	size_t	i;

	i = ~0UL;
	while (ac > ++i)
		if ('-' == av[i][0]
		&& (('-' == av[i][1] && ft_isalpha_str(av[i] + 2))
			|| ft_isalpha_str(av[i] + 1)))
		{
			if (!add_curr_fparse(env, av, ac, &i))
				return (false);
		}
		else
			IFDO_F(true, ERRIN_N(av[i], i + 1, E_SEMATICS_FLAG));
	add_valid_parsed_flags(&env->flags);
	return (true);
}
