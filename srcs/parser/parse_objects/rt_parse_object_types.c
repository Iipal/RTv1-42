/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_object_types.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:40:27 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 08:36:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_rt.h"
#include "rtv1_scene_parse.h"

static bool	add_main_params(JSON_Object const *const object_obj,
	size_t const obj_i,
	Object *const obj,
	char const *const param)
{
	NODO_F(json_object_has_value_of_type(object_obj, "position", JSONArray),
		ERRIN_N(E_OPOS_MISS, obj_i + 1, E_IN_OBJ));
	NODO_F(json_object_has_value_of_type(object_obj, "color", JSONString),
		ERRIN_N(E_OCLR_MISS, obj_i + 1, E_IN_OBJ));
	NODO_F(json_object_has_value_of_type(object_obj, "specular", JSONNumber),
		ERRIN_N(E_OSPEC_MISS, obj_i + 1, E_IN_OBJ));
	NO_F(rt_parse_arr_to_vec(json_object_get_array(object_obj, "position"),
		&obj->pos, param, obj_i));
	NO_F(rt_parse_color((char*)json_object_get_string(object_obj, "color"),
		&obj->clr, obj_i));
	obj->spec = json_object_get_number(object_obj, "specular");
	return (true);
}

bool		rt_parse_sphere(JSON_Object const *const object_obj,
				Object *const obj, size_t const obj_i)
{
	NO_F(add_main_params(object_obj, obj_i, obj, "Sphere"));
	NODO_F(json_object_has_value_of_type(object_obj, "radius", JSONNumber),
		ERRIN_N(E_ORADIUS_MISS, obj_i + 1, E_IN_OBJ));
	IFDO_F(json_object_has_value(object_obj, "direction"),
		ERRIN_N(E_SPHERE_DIR, obj_i + 1, E_IN_OBJ));
	IFDO(Y(obj->pos) != 0.0f, Y(obj->pos) = -Y(obj->pos));
	obj->radius = json_object_get_number(object_obj, "radius");
	obj->fn_inter_calc = rt_inter_sphere;
	obj->fn_normal_calc = rt_normal_sphere;
	obj->fn_uv = rt_uv_sphere;
	obj->type = sphere;
	return (true);
}

bool		rt_parse_cone(JSON_Object const *const object_obj,
				Object *const obj, size_t const obj_i)
{
	NO_F(add_main_params(object_obj, obj_i, obj, "Cone"));
	NODO_F(json_object_has_value_of_type(object_obj, "radius", JSONNumber),
		ERRIN_N(E_ORADIUS_MISS, obj_i + 1, E_IN_OBJ));
	NODO_F(json_object_has_value_of_type(object_obj, "direction", JSONArray),
		ERRIN_N(E_ODIR_MISS, obj_i + 1, E_IN_OBJ));
	NO_F(rt_parse_arr_to_vec(json_object_get_array(object_obj, "direction"),
		&obj->dir, "Cone", obj_i));
	IFDO(Y(obj->pos) != 0.0f, Y(obj->pos) = -Y(obj->pos));
	obj->radius = json_object_get_number(object_obj, "radius");
	obj->fn_inter_calc = rt_inter_cone;
	obj->fn_normal_calc = rt_normal_cone;
	obj->fn_uv = rt_uv_cone;
	obj->type = cone;
	return (true);
}

bool		rt_parse_plane(JSON_Object const *const object_obj,
				Object *const obj, size_t const obj_i)
{
	NO_F(add_main_params(object_obj, obj_i, obj, "Plane"));
	NODO_F(json_object_has_value_of_type(object_obj, "direction", JSONArray),
		ERRIN_N(E_ODIR_MISS, obj_i + 1, E_IN_OBJ));
	IFDO_F(json_object_has_value(object_obj, "radius"),
		ERRIN_N(E_PLANE_RAD, obj_i + 1, E_IN_OBJ));
	NO_F(rt_parse_arr_to_vec(json_object_get_array(object_obj, "direction"),
		&obj->dir, "Plane", obj_i));
	IFDO(Y(obj->pos) != 0.0f, Y(obj->pos) = -Y(obj->pos));
	obj->fn_inter_calc = rt_inter_plane;
	obj->fn_normal_calc = rt_normal_plane;
	obj->fn_uv = rt_uv_plane;
	obj->type = plane;
	return (true);
}

bool		rt_parse_cylinder(JSON_Object const *const object_obj,
				Object *const obj, size_t const obj_i)
{
	NO_F(add_main_params(object_obj, obj_i, obj, "Cylinder"));
	NODO_F(json_object_has_value_of_type(object_obj, "radius", JSONNumber),
		ERRIN_N(E_ORADIUS_MISS, obj_i + 1, E_IN_OBJ));
	NODO_F(json_object_has_value_of_type(object_obj, "direction", JSONArray),
		ERRIN_N(E_ODIR_MISS, obj_i + 1, E_IN_OBJ));
	NO_F(rt_parse_arr_to_vec(json_object_get_array(object_obj, "direction"),
		&obj->dir, "Cylinder", obj_i));
	IFDO(Y(obj->pos) != 0.0f, Y(obj->pos) = -Y(obj->pos));
	obj->radius = json_object_get_number(object_obj, "radius");
	obj->fn_inter_calc = rt_inter_cylinder;
	obj->fn_normal_calc = rt_normal_cylinder;
	obj->fn_uv = rt_uv_cylinder;
	obj->type = cylinder;
	return (true);
}
