/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:35:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 10:18:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_fparse_curr_flags(Flags *f, strtab av,
							const size_t ac, size_t *i_av)
{
	const string		flags[] = {F_HELP, F_VPS, F_SB};
	const string		sflags[] = {SF_HELP, SF_VPS, SF_SB};
	const t_fn_fparse	fns[] = {rt_fhelp, rt_fvps, rt_fsb};
	size_t				i;
	bool				is_valid_flag;

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

bool		rt_fparser(Flags *f, strtab av, const size_t ac)
{
	size_t	i;

	i = ~0L;
	while (ac > ++i)
		if (av[i][0] == '-'
		&& (av[i][1] == '-' || ft_isalpha(av[i][1])))
		{
			NO_F(add_fparse_curr_flags(f, av, ac, &i));
		}
		else
			IFM_F(E_IFLAG, true);
	return (true);
}
