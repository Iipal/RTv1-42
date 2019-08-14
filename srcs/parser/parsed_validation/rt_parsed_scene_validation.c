/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsed_scene_validation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 10:05:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/14 08:45:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	s_valid_lights_data(Light *restrict const l, ssize_t const ins_l)
{
	ssize_t		i;

	i = ins_l;
	while (0 <= --i)
	{
		NODO_F(u_vec_range(l[i].pos, MAX_X, MIN_X),
			ERRIN_N(E_LIGHTPOS, i + 1L, E_IN_LIGHT));
		NODO_F(u_isd_range(l[i].intens, MAX_L_INTENS, MIN_L_INTENS),
			ERRIN_N(E_LINTENSE, i + 1L, E_IN_LIGHT));
		l[i].dir = u_inrange_dir_max(l[i].dir);
		l[i].dir = u_inrange_dir_min(l[i].dir);
	}
	return (true);
}

bool		rt_parsed_scene_validation(Scene *restrict const s)
{
	ssize_t	i;

	i = s->ins_objs;
	NOM_F(E_NOCAM, s->is_camera_exist);
	NOM_F(E_CAMPOS, u_vec_range(s->cam.pos, MAX_X, MIN_X));
	s->cam.dir = u_inrange_dir_max(s->cam.dir);
	s->cam.dir = u_inrange_dir_min(s->cam.dir);
	NO_F(s_valid_lights_data(s->lights, s->ins_lights));
	while (0 <= --i)
	{
		NODO_F(u_vec_range(s->objs[i].pos, MAX_X, MIN_X),
			ERRIN_N(E_OBJPOS, i + 1L, E_IN_OBJ));
		IFDO_F(cone == s->objs[i].type &&
			(M_PI < s->objs[i].radius || s->objs[i].radius <= 0.0),
			ERRIN_N(E_OCONERAD, i + 1L, E_IN_OBJ));
		NODO_F(u_isd_range(s->objs[i].radius, MAX_RADIUS, MIN_RADIUS),
			ERRIN_N(E_OBJRAD, i + 1L, E_IN_OBJ));
		NODO_F(u_isd_range(s->objs[i].spec, MAX_SPEC, MIN_SPEC),
			ERRIN_N(E_OBJRAD, i + 1L, E_IN_OBJ));
		s->objs[i].dir = u_inrange_dir_max(s->objs[i].dir);
		s->objs[i].dir = v_norm(u_inrange_dir_min(s->objs[i].dir));
	}
	return (true);
}
