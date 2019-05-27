/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_fps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:19:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 23:12:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_fftc(Flags *const f, strtab av,
				const size_t ac, size_t *const av_i)
{
	IFM_F(E_MP_FTC, ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_FTC_NO0X, ft_strncmp(av[*av_i], E_FTC0X, ft_strlen(E_FTC0X)));
	av[*av_i] += 2;
	NOM_F(E_FTC_HEX, ft_ishex_str(av[*av_i]));
	NOM_F(E_FTC_ZERO, f->fps_text_color = ft_atoi_base(av[*av_i], 16));
	f->is_parsed_ftc = true;
	return (true);
}

inline bool	rt_ffrt(Flags *const f, strtab av,
				const size_t ac, size_t *const av_i)
{
	IFM_F(E_MP_FRT, ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_UNSIGN, '-' == av[*av_i][0] && ft_isdigit(av[*av_i][1]));
	NOM_F(E_DIGITS, ft_isdigits_str(av[*av_i]));
	IFM_F(E_WARN_FRT, E_MAX_FRT < (f->fps_refresh_timer = ft_atoi(av[*av_i])));
	f->fps_refresh_timer /= 100.0f;
	f->is_parsed_frt = true;
	return (true);
}
