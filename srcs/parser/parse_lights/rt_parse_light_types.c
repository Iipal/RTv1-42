/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_light_types.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:00:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/19 13:43:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_parse_point_light(JSON_Object const *const light_obj,
			Light *const light,
			size_t const light_i)
{
	IFDO_F(json_object_has_value(light_obj, "direction"),
		ERRIN_N(E_LPOINT_DIR, light_i + 1, E_IN_LIGHT));
	NODO_F(json_object_has_value_of_type(light_obj, "position", JSONArray),
		ERRIN_N(E_LPOS_MISS, light_i + 1, E_IN_LIGHT));
	NODO_F(json_object_has_value_of_type(light_obj, "intensity", JSONNumber),
		ERRIN_N(E_LINTENS_MISS, light_i + 1, E_IN_LIGHT));
	NO_F(rt_parse_arr_to_vec(json_object_get_array(light_obj, "position"),
		&light->pos, "Light", light_i));
	light->intens = json_object_get_number(light_obj, "intensity");
	IFDO_F(0.0f > light->intens,
		ERRIN_N(E_LI_LESS_ZERO, light_i + 1, E_IN_LIGHT));
	IFDO_F(1.0f < light->intens,
		ERRIN_N(E_LI_GRT_ZERO, light_i + 1, E_IN_LIGHT));
	IFDO(Y(light->pos) != 0.0f, Y(light->pos) = -Y(light->pos));
	light->type = point;
	return (true);
}

bool	rt_parse_dir_light(JSON_Object const *const light_obj,
			Light *const light,
			size_t const light_i)
{
	NODO_F(json_object_has_value_of_type(light_obj, "direction", JSONArray),
		ERRIN_N(E_LDIR_MISS, light_i + 1, E_IN_LIGHT));
	NODO_F(json_object_has_value_of_type(light_obj, "position", JSONArray),
		ERRIN_N(E_LPOS_MISS, light_i + 1, E_IN_LIGHT));
	NODO_F(json_object_has_value_of_type(light_obj, "intensity", JSONNumber),
		ERRIN_N(E_LINTENS_MISS, light_i + 1, E_IN_LIGHT));
	NO_F(rt_parse_arr_to_vec(json_object_get_array(light_obj, "position"),
		&light->pos, "Light", light_i));
	NO_F(rt_parse_arr_to_vec(json_object_get_array(light_obj, "direction"),
		&light->dir, "Light", light_i));
	light->intens = json_object_get_number(light_obj, "intensity");
	IFDO_F(MIN_L_INTENS > light->intens,
		ERRIN_N(E_LI_LESS_ZERO, light_i + 1, E_IN_LIGHT));
	IFDO_F(MAX_L_INTENS < light->intens,
		ERRIN_N(E_LI_GRT_ZERO, light_i + 1, E_IN_LIGHT));
	IFDO(Y(light->pos) != 0.0f, Y(light->pos) = -Y(light->pos));
	light->type = direct;
	return (true);
}
