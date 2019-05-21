/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:30:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/21 09:59:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_fvps(Flags *const f, strtab av,
				const size_t ac, size_t *const av_i)
{
	IFM_F(E_MP_VPS, ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_UNSIGN, '-' == av[*av_i][0]);
	NOM_F(E_DIGITS, ft_isdigits_str(av[*av_i]));
	IFM_F(E_WARNVPS, 10.0f < (f->viewport_scale = ft_atoi(av[*av_i])));
	NOM_F(E_WVPSZERO, f->viewport_scale);
	return (true);
}

inline bool	rt_fsb(Flags *const f, strtab av,
				const size_t ac, size_t *const av_i)
{
	IFM_F(E_MP_SB, ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_UNSIGN, '-' == av[*av_i][0]);
	NOM_F(E_DIGITS, ft_isdigits_str(av[*av_i]));
	IFM_F(E_WARNSB, 10.0f < (f->shadows_bright = ft_atoi(av[*av_i])));
	NOM_F(E_WSBZERO, f->shadows_bright);
	return (true);
}

inline bool	rt_fftc(Flags *const f, strtab av,
				const size_t ac, size_t *const av_i)
{
	IFM_F(E_MP_FTC, ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_UNSIGN, '-' == av[*av_i][0]);
	IFM_F(E_FTC_NO0X, ft_strncmp(av[*av_i], E_FTC0X, ft_strlen(E_FTC0X)));
	av[*av_i] += 2;
	NOM_F(E_FTC_HEX, ft_ishex_str(av[*av_i]));
	NOM_F(E_WFTCZERO, f->fps_text_color = ft_atoi_base(av[*av_i], 16));
	return (true);
}

inline bool	rt_fdbg(Flags *const f, strtab av,
				const size_t ac, size_t *const av_i)
{
	(void)av;
	(void)ac;
	(void)av_i;
	f->debug_mode = true;
	return (true);
}

inline bool	rt_fncl(Flags *const f, strtab av,
				const size_t ac, size_t *const av_i)
{
	(void)av;
	(void)ac;
	(void)av_i;
	f->no_calc_light = true;
	return (true);
}
