/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:51:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/10 10:17:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		rt_fps(Fps *restrict const fps, double_t const cam_speed)
{
	fps->time.old = fps->time.current;
	fps->time.current = SDL_GetTicks();
	fps->time.res = (fps->time.current - fps->time.old) / 1000.0f;
	fps->move = fps->time.res * MOVE_INC * cam_speed;
	fps->l_move = fps->move * 5.0f;
	fps->l_intens = fps->move / 5.0f;
	fps->o_spec_intens = fps->move * 100.0f;
}
