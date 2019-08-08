/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_flags_with_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 18:30:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/08 22:37:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	f_vps(Flags *const f, char **av,
			const size_t ac, size_t *const av_i)
{
	if (IS_BIT(g_flags, F_BIT_VPS))
	{
		MSGN(E_REPEAT_FLAG(E_VPS));
		return (true);
	}
	IFM_F(E_MISS_PARAM(E_VPS), ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_UNSIGN, '-' == av[*av_i][0] && F_ISDIGIT(av[*av_i][1]));
	NOM_F(E_DIGITS, ft_isfdigits_str(av[*av_i]));
	IFM_F(E_WARN_VPS, E_MAX_VPS < (f->viewport_scale = ft_atof(av[*av_i])));
	NOM_F(E_ZERO_PARAM(E_VPS), f->viewport_scale);
	SET_BIT(g_flags, F_BIT_VPS);
	return (true);
}

bool	f_al(Flags *const f, char **av,
			const size_t ac, size_t *const av_i)
{
	if (IS_BIT(g_flags, F_BIT_AL))
	{
		MSGN(E_REPEAT_FLAG(E_AL));
		return (true);
	}
	IFM_F(E_MISS_PARAM(E_AL), ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_UNSIGN, '-' == av[*av_i][0] && F_ISDIGIT(av[*av_i][1]));
	NOM_F(E_DIGITS, ft_isfdigits_str(av[*av_i]));
	IFM_F(E_WARN_AL, E_MAX_AL < (f->ambient_light = ft_atof(av[*av_i])));
	NOM_F(E_ZERO_PARAM(E_AL), f->ambient_light);
	f->ambient_light = E_MAX_AL - f->ambient_light;
	SET_BIT(g_flags, F_BIT_AA);
	return (true);
}

bool	f_ftc(Flags *const f, char **av,
			const size_t ac, size_t *const av_i)
{
	if (IS_BIT(g_flags, F_BIT_FTC))
	{
		MSGN(E_REPEAT_FLAG(E_FTC));
		return (true);
	}
	IFM_F(E_MISS_PARAM(E_FTC), ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_FTC_NO0X, ft_strncmp(av[*av_i], E_FTC0X, ft_strlen(E_FTC0X)));
	av[*av_i] += 2;
	NOM_F(E_FTC_HEX, ft_ishex_str(av[*av_i]));
	NOM_F(E_FTC_ZERO, f->fps_text_color.hex = ft_atoi_base(av[*av_i], 16));
	SET_BIT(g_flags, F_BIT_FTC);
	return (true);
}

bool	f_frt(Flags *const f, char **av,
			const size_t ac, size_t *const av_i)
{
	if (IS_BIT(g_flags, F_BIT_FRT))
	{
		MSGN(E_REPEAT_FLAG(E_FRT));
		return (true);
	}
	IFM_F(E_MISS_PARAM(E_FRT), ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_UNSIGN, '-' == av[*av_i][0] && F_ISDIGIT(av[*av_i][1]));
	NOM_F(E_DIGITS, ft_isdigits_str(av[*av_i]));
	IFM_F(E_WARN_FRT, E_MAX_FRT < (f->fps_refresh_timer = ft_atoi(av[*av_i])));
	f->fps_refresh_timer /= 100.0f;
	SET_BIT(g_flags, F_BIT_FRT);
	return (true);
}

bool	f_aa(Flags *const f, char **av,
			const size_t ac, size_t *const av_i)
{
	if (IS_BIT(g_flags, F_BIT_AA))
	{
		MSGN(E_REPEAT_FLAG(E_AA));
		return (true);
	}
	IFM_F(E_MISS_PARAM(E_AA), ac <= ++*av_i);
	av[*av_i] += ft_skip_blanks(av[*av_i]);
	IFM_F(E_UNSIGN, '-' == av[*av_i][0] && F_ISDIGIT(av[*av_i][1]));
	NOM_F(E_DIGITS, ft_isdigits_str(av[*av_i]));
	IFM_F(E_WARN_AA, E_MAX_AA < (f->anti_aliasing = ft_atoi(av[*av_i])));
	IFM_F(E_AA_USLS, 1 >= f->anti_aliasing);
	SET_BIT(g_flags, F_BIT_AA);
	return (true);
}
