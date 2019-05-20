/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:35:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/20 16:09:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_curr_fparse(Flags *const f, strtab av,
							const size_t ac,
							size_t *const i_av)
{
	const string		flags[] = {F_HELP, F_VPS, F_SB, F_FTC, F_DBG};
	const string		sflags[] = {SF_HELP, SF_VPS, SF_SB, SF_FTC, SF_DBG};
	const t_fn_fparse	fns[] = {rt_fhelp, rt_fvps, rt_fsb, rt_fftc, rt_fdbg};
	bool				is_valid_flag;
	size_t				i;

	i = ~0L;
	is_valid_flag = false;
	while (MAX_FLAGS > ++i)
		if (ft_is_one_of_str(av[*i_av], false, 2, flags[i], sflags[i]))
		{
			is_valid_flag = true;
			return (fns[i](f, av, ac, i_av));
		}
	NOM_F(E_IFLAG, is_valid_flag);
	return (is_valid_flag);
}

bool		rt_flags_parser(Flags *const f, strtab av, const size_t ac)
{
	size_t	i;

	i = ~0L;
	while (ac > ++i)
		if (av[i][0] == '-'
		&& (av[i][1] == '-' || ft_isalpha(av[i][1])))
		{
			NO_F(add_curr_fparse(f, av, ac, &i));
		}
		else
			IFM_F(E_IFLAG, true);
	return (true);
}
