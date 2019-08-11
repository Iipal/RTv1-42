/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:04:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/11 13:50:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_scene_parse.h"

static bool	s_parse_current_object(JSON_Object const *const object_obj,
				Object *const obj,
				size_t const curr_obj)
{
	t_fn_obj const	fn_objs[] = {rt_parse_sphere, rt_parse_cone,
								rt_parse_plane, rt_parse_cylinder};
	char const		*o_types[] = {FP_SPHERE, FP_CONE, FP_PLANE, FP_CYLINDER};
	char const		*obj_type = json_object_get_string(object_obj, "type");
	size_t			i;

	i = ~0ULL;
	NODO_F(object_obj, ERRIN_N(E_INVALID_OBJ, i + 1, E_IN_LINE));
	NODO_F(obj_type, ERRIN_N(E_OTYPE_MISS, curr_obj + 1, E_IN_OBJ));
	while (max_objs > ++i)
		if (!ft_strncmp((char*)obj_type, o_types[i], ft_strlen(o_types[i])))
			return (fn_objs[i](object_obj, obj, curr_obj));
	NODO_F(false, ERRIN_N(E_UNKNOWN_OBJ_TYPE, curr_obj + 1, E_IN_OBJ));
	return (true);
}

bool		rt_parse_objects(Scene *const scene,
				JSON_Object const *const root_obj)
{
	JSON_Value const	*o_value = json_object_get_value(root_obj, "Objects");
	JSON_Array			*objects_arr;
	size_t				i;

	i = ~0ULL;
	NOM_F(E_NOOBJS, o_value);
	IFM_F(E_OARR_TYPE, JSONArray != json_value_get_type(o_value));
	NOM_F(E_NOOBJS, objects_arr = json_value_get_array(o_value));
	NOM_F(E_NOOBJS, scene->ins_objs = json_array_get_count(objects_arr));
	MEM(Object, scene->objs, scene->ins_objs, E_ALLOC);
	while (scene->ins_objs > ++i)
		NO_F(s_parse_current_object(json_array_get_object(objects_arr, i),
				&scene->objs[i], i));
	return (true);
}
