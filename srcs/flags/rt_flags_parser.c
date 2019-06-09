/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:35:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/09 14:35:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool			add_curr_fparse(Environment *restrict const env,
						strtab av, const size_t ac, size_t *const av_i)
{
	const t_fbool	fbool[] = {rt_fdbg, rt_fncl, rt_ftex, rt_frli, rt_fpu};
	const t_fwparam	fwparam[] = {rt_fvps, rt_fal, rt_fftc, rt_ffrt};
	size_t			fn_num;

	if (ft_is_one_of_str(av[*av_i], false, 2UL, SF_HELP, F_HELP))
	{
		ft_putfile(RTV1_FUSAGE);
		return (false);
	}
	else if ((fn_num = rt_is_flag_boolean(av[*av_i])))
		return (fbool[fn_num - 1](&env->flags));
	else if ((fn_num = rt_is_flag_wparam(av[*av_i])))
		return (fwparam[fn_num - 1](&env->flags, av, ac, av_i));
	else
		ERRIN(E_INVALID_FLAG, av[*av_i]);
	return (false);
}

static inline __attribute__((always_inline)) void	add_valid_parsed_flags(
	const Flags *restrict const f)
{
	if (f->is_parsed_frt && !f->debug_mode)
		MSGN(E_USELESS_FRT);
	if (f->is_parsed_ftc && !f->debug_mode)
		MSGN(E_USELESS_FTC);
	if (f->print_usage && !f->debug_mode)
		MSGN(E_USELESS_PU);
	if (f->random_lights_intense && f->no_calc_light)
		MSGN(E_USELESS_RLI);
	if (E_MAX_AL > f->ambient_light && f->no_calc_light)
		MSGN(E_USELESS_AL);
}

bool				rt_flags_parser(Environment *restrict const env,
									strtab av, const size_t ac)
{
	size_t	i;

	i = ~0UL;
	while (ac > ++i)
		if ('-' == av[i][0]
		&& (('-' == av[i][1] && ft_isalpha_str(av[i] + 2))
			|| ft_isalpha_str(av[i] + 1)))
		{
			NO_F(add_curr_fparse(env, av, ac, &i));
		}
		else
			IFDO_F(true, ERRIN_N(av[i], i + 1, E_CEMANTIC_FLAG));
	add_valid_parsed_flags(&env->flags);
	return (true);
}
