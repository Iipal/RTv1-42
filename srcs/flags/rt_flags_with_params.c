/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_with_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:30:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/28 11:58:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_fvps(Flags *const f, strtab av,
				const size_t ac, size_t *const av_i)
{
	IFM_F(E_MP_VPS, ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_UNSIGN, '-' == av[*av_i][0] && ft_isdigit(av[*av_i][1]));
	NOM_F(E_DIGITS, ft_isdigits_str(av[*av_i]));
	IFM_F(E_WARN_VPS, E_MAX_VPS < (f->viewport_scale = ft_atoi(av[*av_i])));
	NOM_F(E_VPS_ZERO, f->viewport_scale);
	return (true);
}

inline bool	rt_fsb(Flags *const f, strtab av,
				const size_t ac, size_t *const av_i)
{
	IFM_F(E_MP_SB, ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_UNSIGN, '-' == av[*av_i][0] && ft_isdigit(av[*av_i][1]));
	NOM_F(E_DIGITS, ft_isdigits_str(av[*av_i]));
	IFM_F(E_WARN_SB, E_MAX_SB < (f->shadow_bright = ft_atoi(av[*av_i])));
	NOM_F(E_SB_ZERO, f->shadow_bright);
	return (true);
}
