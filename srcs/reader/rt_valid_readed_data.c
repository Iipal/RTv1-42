/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_valid_readed_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 10:05:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/18 10:12:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_valid_lights_data(Scene *s)
{
	size_t	i;

	i = ~0L;
	while (s->ins_l > ++i)
	{
		NODO_F(u_inrangev(s->l[i].pos, true, true),
			ERRIN(E_LIGHTPOS, i + 1, E_IN_LIGHT));
		IFDO_F(MIN_L_INTENS > s->l[i].intens
			|| MAX_L_INTENS < s->l[i].intens,
			ERRIN(E_LINTENSE, i + 1, E_IN_LIGHT));
	}
	return (true);
}

bool		rt_valid_readed_data(Scene *s)
{
	size_t	i;

	NOM_F(E_NOCAM, s->cam.is);
	NOM_F(E_CAMPOS, u_inrangev(s->cam.pos, true, true));
	s->cam.dir = u_inrange_dir_max(s->cam.dir);
	s->cam.dir = u_inrange_dir_min(s->cam.dir);
	NO_F(add_valid_lights_data(s));
	i = ~0L;
	while (s->ins_objs > ++i)
	{
		NODO_F(u_inrangev(s->objs[i].pos, true, true),
			ERRIN(E_OBJPOS, i + 1, E_IN_OBJ));
		IFDO_F(MIN_RADIUS > s->objs[i].radius
		|| MAX_RADIUS > s->objs[i].radius, ERRIN(E_OBJRAD, i + 1, E_IN_OBJ));
		IFDO_F(MIN_SPEC > s->objs[i].spec || MAX_SPEC < s->objs[i].spec,
			ERRIN(E_OBJRAD, i + 1, E_IN_OBJ));
		s->objs[i].dir = u_inrange_dir_max(s->objs[i].dir);
		s->objs[i].dir = u_inrange_dir_min(s->objs[i].dir);
	}
	return (true);
}
