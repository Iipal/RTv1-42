/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_object_types.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:40:27 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/15 23:06:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_parse_sphere(const JSON_Object *const object_obj,
			Object *const obj, const size_t curr_obj)
{
	NODO_F(rt_parse_exclude_param(object_obj, "direction"),
		ERRIN_N(E_SPHERE_DIR, curr_obj + 1, E_IN_OBJ));
	NODO_F(json_object_has_value_of_type(object_obj, "position", JSONArray),
		ERRIN_N(E_OPOS_MISS, curr_obj + 1, E_IN_OBJ));
	NODO_F(json_object_has_value_of_type(object_obj, "color", JSONString),
		ERRIN_N(E_OCLR_MISS, curr_obj + 1, E_IN_OBJ));
	NODO_F(json_object_has_value_of_type(object_obj, "radius", JSONNumber),
		ERRIN_N(E_ORADIUS_MISS, curr_obj + 1, E_IN_OBJ));
	NODO_F(json_object_has_value_of_type(object_obj, "specular", JSONNumber),
		ERRIN_N(E_OSPEC_MISS, curr_obj + 1, E_IN_OBJ));
	NO_F(rt_parse_arr_to_vec(json_object_get_array(object_obj, "position"),
		&obj->pos, "Light", curr_obj));
	NO_F(rt_parse_color((string)json_object_get_string(object_obj, "color"),
		&obj->clr, curr_obj));
	IFDO(Y(obj->pos) != 0.0f, Y(obj->pos) = -Y(obj->pos));
	obj->radius = json_object_get_number(object_obj, "radius");
	obj->spec = json_object_get_number(object_obj, "specular");
	obj->fn_inter_calc = rt_inter_sphere;
	obj->fn_normal_calc = rt_normal_sphere;
	obj->fn_uv = rt_uv_sphere;
	obj->type = sphere;
	return (true);
}

bool	rt_parse_plane(const JSON_Object *const object_obj,
			Object *const obj, const size_t curr_obj)
{
	NODO_F(rt_parse_exclude_param(object_obj, "radius"),
		ERRIN_N(E_PLANE_RAD, curr_obj + 1, E_IN_OBJ));
	NODO_F(json_object_has_value_of_type(object_obj, "direction", JSONArray),
		ERRIN_N(E_ODIR_MISS, curr_obj + 1, E_IN_OBJ));
	NODO_F(json_object_has_value_of_type(object_obj, "position", JSONArray),
		ERRIN_N(E_OPOS_MISS, curr_obj + 1, E_IN_OBJ));
	NODO_F(json_object_has_value_of_type(object_obj, "color", JSONString),
		ERRIN_N(E_OCLR_MISS, curr_obj + 1, E_IN_OBJ));
	NODO_F(json_object_has_value_of_type(object_obj, "specular", JSONNumber),
		ERRIN_N(E_OSPEC_MISS, curr_obj + 1, E_IN_OBJ));
	NO_F(rt_parse_arr_to_vec(json_object_get_array(object_obj, "position"),
		&obj->pos, "Plane", curr_obj));
	NO_F(rt_parse_arr_to_vec(json_object_get_array(object_obj, "direction"),
		&obj->dir, "Plane", curr_obj));
	NO_F(rt_parse_color((string)json_object_get_string(object_obj, "color"),
		&obj->clr, curr_obj));
	IFDO(Y(obj->pos) != 0.0f, Y(obj->pos) = -Y(obj->pos));
	obj->spec = json_object_get_number(object_obj, "specular");
	obj->fn_inter_calc = rt_inter_plane;
	obj->fn_normal_calc = rt_normal_plane;
	obj->fn_uv = rt_uv_plane;
	obj->type = plane;
	return (true);
}
