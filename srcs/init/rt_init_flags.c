/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/17 11:08:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_init_flags(Flags *restrict const flags)
{
	*flags = (Flags) { DEF_FPS_TEXT_COLOR,
						DEF_FPS_REFRESH_TIMER,
						DEF_VIEWPORT_SCALE,
						DEF_AMBIENT_LIGHT,
						DEF_ANTI_ALIASING,
						false, false, false, false, false,
						DEF_DEBUG_MODE,
						DEF_NO_CALC_LIGHT,
						DEF_TEXTURED,
						DEF_RANDOM_INTENSE,
						DEF_PRINT_USAGE };
}
