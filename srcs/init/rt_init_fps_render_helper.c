/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_fps_render_helper.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:38:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/10 15:05:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

FpsRenderHelper	*rt_init_fps_render_helper(void)
{
	FpsRenderHelper *out;

	out = NULL;
	MEM(FpsRenderHelper, out, 1, E_ALLOC);
	return out;
}
