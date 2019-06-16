/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_lights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 09:47:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/16 14:03:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_scene_parse.h"

static bool	add_parse_current_light(JSON_Object *light_obj,
				Light *const l,
				const size_t curr_light)
{
	const t_fn_lght	fn_lights[] = {rt_parse_point_light, rt_parse_dir_light};
	const string	l_types[] = {LT_POINT, LT_DIRECT};
	const char		*light_type = json_object_get_string(light_obj, "type");
	size_t			i;

	i = ~0ULL;
	NODO_F(light_type, ERRIN_N(E_LTYPE_MISS, curr_light + 1, E_IN_LIGHT));
	while (MAX_LT > ++i)
		if (!ft_strncmp((string)light_type, l_types[i], ft_strlen(l_types[i])))
			return (fn_lights[i](light_obj, l, curr_light));
	NODO_F(false, ERRIN_N(E_UNKNOWN_LGT_TYPE, curr_light + 1, E_IN_LIGHT));
	return (true);
}

bool		rt_parse_lights(Scene *const scene,
				const JSON_Object *const root_obj)
{
	const JSON_Value	*l_value = json_object_get_value(root_obj, "Lights");
	JSON_Array			*lights_arr;
	JSON_Object			*light_obj;
	size_t				i;

	i = ~0ULL;
	NOM_F(E_NOLIGHT, l_value);
	IFM_F(E_LARR_TYPE, JSONArray != json_value_get_type(l_value));
	NOM_F(E_NOLIGHT, lights_arr = json_value_get_array(l_value));
	NOM_F(E_NOLIGHT, scene->ins_lights = json_array_get_count(lights_arr));
	MEM(Light, scene->lights, scene->ins_lights, E_ALLOC);
	while (scene->ins_lights > ++i)
	{
		NODO_F(light_obj = json_array_get_object(lights_arr, i),
			ERRIN_N(E_INVALID_LGT, i + 1, E_IN_LINE));
		NO_F(add_parse_current_light(light_obj, &scene->lights[i], i));
	}
	return (true);
}
