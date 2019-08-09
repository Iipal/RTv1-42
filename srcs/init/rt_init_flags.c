/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 08:25:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

uint16_t g_flags = 0;

void	rt_init_flags(Flags *restrict const flags)
{
	*flags = (Flags) { DEF_FPS_TEXT_COLOR,
						DEF_FPS_REFRESH_TIMER,
						DEF_VIEWPORT_SCALE,
						DEF_AMBIENT_LIGHT,
						DEF_ANTI_ALIASING };
}
