/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:35:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 17:53:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	s_curr_fparse(Environment *restrict const env,
				char **av, size_t const ac, size_t *const av_i)
{
	t_fbool const	fbool[] = {f_dbg, f_ncl, f_tex, f_rli, f_pu};
	t_fwparam const	fwparam[] = {f_vps, f_al, f_ftc, f_frt, f_aa};
	t_fother const	fother[] = {f_nb};
	size_t			fn_num;

	if (ft_is_one_of_n((const char *restrict)av[*av_i], 2UL, SF_HELP, F_HELP))
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

bool		rt_parse_flags(Environment *const env, char **av, size_t const ac)
{
	size_t	i;

	i = ~0UL;
	while (ac > ++i)
		if ('-' == av[i][0]
		&& (('-' == av[i][1] && ft_isalpha_str(av[i] + 2))
			|| ft_isalpha_str(av[i] + 1)))
		{
			if (!s_curr_fparse(env, av, ac, &i))
				return (false);
		}
		else
			IFDO_F(true, ERRIN_N(av[i], i + 1, E_SEMATICS_FLAG));
	return (true);
}
