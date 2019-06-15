/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_light_types.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:00:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/15 15:54:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool			rt_parse_point_light(const JSON_Object *const light_obj,
							Light *const light,
							const size_t curr_light)
{
	light->type = direct;
	NODO_F(json_object_has_value_of_type(light_obj, "direction", JSONArray),
		ERRIN_N(E_LPOINT_DIR, curr_light + 1, E_IN_LIGHT));
	NODO_F(json_object_has_value_of_type(light_obj, "position", JSONArray),
		ERRIN_N(E_LPOS_MISS, curr_light + 1, E_IN_LIGHT));
	NODO_F(json_object_has_value_of_type(light_obj, "intensity", JSONNumber),
		ERRIN_N(E_LINTENS_MISS, curr_light + 1, E_IN_LIGHT));
	NO_F(rt_parse_arr_to_vec(json_object_get_array(light_obj, "position"),
		&light->pos, "Light", curr_light));
	light->intens = json_object_get_number(light_obj, "intensity");
	IFDO_F(0.0f > light->intens,
		ERRIN_N(E_LI_LESS_ZERO, curr_light + 1, E_IN_LIGHT));
	IFDO_F(1.0f < light->intens,
		ERRIN_N(E_LI_GRT_ZERO, curr_light + 1, E_IN_LIGHT));
	return (true);
}

bool			rt_parse_dir_light(const JSON_Object *const light_obj,
							Light *const light,
							const size_t curr_light)
{
	light->type = direct;
	NODO_F(json_object_has_value_of_type(light_obj, "direction", JSONArray),
		ERRIN_N(E_LDIR_MISS, curr_light + 1, E_IN_LIGHT));
	NODO_F(json_object_has_value_of_type(light_obj, "position", JSONArray),
		ERRIN_N(E_LPOS_MISS, curr_light + 1, E_IN_LIGHT));
	NODO_F(json_object_has_value_of_type(light_obj, "intensity", JSONNumber),
		ERRIN_N(E_LINTENS_MISS, curr_light + 1, E_IN_LIGHT));
	NO_F(rt_parse_arr_to_vec(json_object_get_array(light_obj, "position"),
		&light->pos, "Light", curr_light));
		NO_F(rt_parse_arr_to_vec(json_object_get_array(light_obj, "direction"),
		&light->dir, "Light", curr_light));
	light->intens = json_object_get_number(light_obj, "intensity");
	IFDO_F(MIN_L_INTENS > light->intens,
		ERRIN_N(E_LI_LESS_ZERO, curr_light + 1, E_IN_LIGHT));
	IFDO_F(MAX_L_INTENS < light->intens,
		ERRIN_N(E_LI_GRT_ZERO, curr_light + 1, E_IN_LIGHT));
	return (true);
}
