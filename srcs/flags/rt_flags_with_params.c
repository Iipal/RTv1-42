/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_with_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:30:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/09 11:46:59 by tmaluh           ###   ########.fr       */
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

inline bool	rt_fal(Flags *const f, strtab av,
				const size_t ac, size_t *const av_i)
{
	IFM_F(E_MP_AL, ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_UNSIGN, '-' == av[*av_i][0] && ft_isdigit(av[*av_i][1]));
	NOM_F(E_DIGITS, ft_isdigits_str(av[*av_i]));
	IFM_F(E_WARN_AL, E_MAX_AL < (f->ambient_light = ft_atoi(av[*av_i])));
	NOM_F(E_AL_ZERO, f->ambient_light);
	return (true);
}
