/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:30:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 11:35:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_fhelp(Flags *f, strtab av, const size_t ac, size_t *av_i)
{
	(void)f;
	(void)ac;
	(void)av;
	(void)av_i;
	ft_putfile(RTV1_FHELP);
	exit(1);
	return (true);
}

inline bool	rt_fvps(Flags *f, strtab av, const size_t ac, size_t *av_i)
{
	IFM_F(E_MP_VPS, ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_UNSIGN, '-' == av[*av_i][0]);
	NOM_F(E_DIGITS, ft_isdigits_str(av[*av_i]));
	IFM_F(E_WARNVPS, 10.0f < (f->viewport_scale = ft_atoi(av[*av_i])));
	NOM_F(E_WVPSZERO, f->viewport_scale);
	return (true);
}

inline bool	rt_fsb(Flags *f, strtab av, const size_t ac, size_t *av_i)
{
	IFM_F(E_MP_SB, ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_UNSIGN, '-' == av[*av_i][0]);
	NOM_F(E_DIGITS, ft_isdigits_str(av[*av_i]));
	IFM_F(E_WARNSB, 10.0f < (f->shadows_bright = ft_atoi(av[*av_i])));
	NOM_F(E_WSBZERO, f->shadows_bright);
	return (true);
}