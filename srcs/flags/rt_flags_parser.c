/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:35:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/09 04:55:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool			add_curr_fparse(Flags *const f, strtab av,
							const size_t ac,
							size_t *const av_i)
{
	const string		flags[] = {F_HELP, F_VPS, F_SB, F_FTC, F_FRT,
							F_DBG, F_NCL, F_TEX, F_RLI, F_PU};
	const string		sflags[] = {SF_HELP, SF_VPS, SF_SB, SF_FTC, SF_FRT,
							SF_DBG, SF_NCL, SF_TEX, SF_RLI, SF_PU};
	const t_fn_fparse	fns[] = {rt_fhelp, rt_fvps, rt_fsb, rt_fftc, rt_ffrt,
							rt_fdbg, rt_fncl, rt_ftex, rt_frli, rt_fpu};
	bool				is_valid_flag;
	size_t				i;

	i = ~0UL;
	is_valid_flag = false;
	while (MAX_FLAGS > ++i)
		if (ft_is_one_of_str(av[*av_i], false, 2, flags[i], sflags[i]))
		{
			is_valid_flag = true;
			return (fns[i](f, av, ac, av_i));
		}
	NODO_F(is_valid_flag, ERRIN(E_INVALID_FLAG, av[*av_i]));
	return (true);
}

static inline void	add_validate_parsed_flags(const Flags *const f)
{
	if (f->is_parsed_frt && !f->debug_mode)
		MSGN(E_USELESS_FRT);
	if (f->is_parsed_ftc && !f->debug_mode)
		MSGN(E_USELESS_FTC);
	if (f->print_usage && !f->debug_mode)
		MSGN(E_USELESS_PU);
	if (f->random_lights_intense && f->no_calc_light)
		MSGN(E_USELESS_RLI);
	if (E_MAX_SB > f->shadow_bright && f->no_calc_light)
		MSGN(E_USELESS_SB);
}

bool				rt_flags_parser(Flags *const f, strtab av, const size_t ac)
{
	size_t	i;

	i = ~0UL;
	while (ac > ++i)
		if ('-' == av[i][0]
		&& (('-' == av[i][1] && ft_isalpha_str(av[i] + 2))
			|| ft_isalpha_str(av[i] + 1)))
		{
			NO_F(add_curr_fparse(f, av, ac, &i));
		}
		else
			IFDO_F(true, ERRIN_N(av[i], i + 1, E_CEMANTIC_FLAG));
	add_validate_parsed_flags(f);
	return (true);
}
