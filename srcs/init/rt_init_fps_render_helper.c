/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_fps_render_helper.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:38:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/11 13:50:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char		*s_prepare_info_str(char const *const str_info)
{
	char	*out;

	MEM(char, out, FPS_MAX_BUFF_SIZE, E_ALLOC);
	ft_memset(out, ' ', FPS_MAX_BUFF_SIZE);
	ft_strcpy(out + (FPS_MAX_BUFF_SIZE - ft_strlen(str_info)), str_info);
	return (out);
}

FpsRenderHelper	*rt_init_fps_render_helper(void)
{
	FpsRenderHelper	*out;

	out = NULL;
	MEM(FpsRenderHelper, out, 1, E_ALLOC);
	NO_F(out->fps_str = s_prepare_info_str("fps"));
	NO_F(out->ms_str = s_prepare_info_str("ms"));
	return out;
}
