/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_valid_readed_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 10:05:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/21 18:52:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_valid_lights_data(Light *const l,
								const double_t ins_l)
{
	size_t	i;

	i = ~0L;
	while (ins_l > ++i)
	{
		NODO_F(u_vec_range(l[i].pos, MAX_X, MIN_X),
			ERRIN(E_LIGHTPOS, i + 1, E_IN_LIGHT));
		NODO_F(u_isd_range(l[i].intens, MAX_L_INTENS, MIN_L_INTENS),
			ERRIN(E_LINTENSE, i + 1, E_IN_LIGHT));
		l[i].dir = u_inrange_dir_max(l[i].dir);
		l[i].dir = u_inrange_dir_min(l[i].dir);
	}
	return (true);
}

bool		rt_valid_readed_data(Scene *const s)
{
	size_t	i;

	i = ~0L;
	NOM_F(E_NOCAM, s->cam.is);
	NOM_F(E_CAMPOS, u_vec_range(s->cam.pos, MAX_X, MIN_X));
	s->cam.dir = u_inrange_dir_max(s->cam.dir);
	s->cam.dir = u_inrange_dir_min(s->cam.dir);
	s->cam.dir = (Vector){VNORM(s->cam.dir)};
	NO_F(add_valid_lights_data(s->l, s->ins_l));
	while (s->ins_objs > ++i)
	{
		NODO_F(u_vec_range(s->objs[i].pos, MAX_X, MIN_X),
			ERRIN(E_OBJPOS, i + 1, E_IN_OBJ));
		IFDO_F(s->objs[i].type == cone &&
			(s->objs[i].radius > 3 || s->objs[i].radius <= 0),
			ERRIN(E_OCONERAD, i + 1, E_IN_OBJ));
		NODO_F(u_isd_range(s->objs[i].radius, MAX_RADIUS, MIN_RADIUS),
			ERRIN(E_OBJRAD, i + 1, E_IN_OBJ));
		NODO_F(u_isd_range(s->objs[i].spec, MAX_SPEC, MIN_SPEC),
			ERRIN(E_OBJRAD, i + 1, E_IN_OBJ));
		s->objs[i].dir = (Vector){VNORM(s->objs[i].dir)};
	}
	return (true);
}
