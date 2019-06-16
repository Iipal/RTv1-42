/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:04:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/16 11:17:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_parse_current_object(JSON_Object *object_obj,
				Object *const obj,
				const size_t curr_obj)
{
	const t_fn_obj	fn_objs[] = {rt_parse_sphere, rt_parse_cone,
								rt_parse_plane, rt_parse_cylinder};
	const string	o_types[] = {FP_SPHERE, FP_CONE, FP_PLANE, FP_CYLINDER};
	const char		*obj_type = json_object_get_string(object_obj, "type");
	size_t			i;

	i = ~0ULL;
	NODO_F(obj_type, ERRIN_N(E_OTYPE_MISS, curr_obj + 1, E_IN_OBJ));
	while (FP_MAX_OBJS > ++i)
		if (!ft_strncmp((string)obj_type, o_types[i], ft_strlen(o_types[i])))
			return (fn_objs[i](object_obj, obj, curr_obj));
	NODO_F(false, ERRIN_N(E_UNKNOWN_OBJ_TYPE, curr_obj + 1, E_IN_OBJ));
	return (true);
}

bool		rt_parse_objects(Scene *const scene,
				JSON_Object *root_obj)
{
	JSON_Value	*objects_value;
	JSON_Array	*objects_arr;
	JSON_Object	*object_obj;
	size_t		i;

	i = ~0ULL;
	NOM_F(E_NOOBJS, objects_value = json_object_get_value(root_obj, "Objects"));
	IFM_F(E_OARR_TYPE, JSONArray != json_value_get_type(objects_value));
	NOM_F(E_NOOBJS, objects_arr = json_value_get_array(objects_value));
	NOM_F(E_NOOBJS, scene->ins_objs = json_array_get_count(objects_arr));
	MEM(Object, scene->objs, scene->ins_objs, E_ALLOC);
	while (scene->ins_objs > ++i)
	{
		NODO_F(object_obj = json_array_get_object(objects_arr, i),
			ERRIN_N(E_INVALID_OBJ, i + 1, E_IN_LINE));
		NO_F(add_parse_current_object(object_obj, &scene->objs[i], i));
	}
	return (true);
}
