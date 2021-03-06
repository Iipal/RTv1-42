/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_lights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 09:47:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 16:36:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	s_parse_current_light(JSON_Object *light_obj, Light *const l,
				size_t const curr_light_i)
{
	t_fn_lght const	fn_lights[] = {rt_parse_point_light, rt_parse_dir_light};
	char const		*l_types[] = {LT_POINT, LT_DIRECT};
	char const		*light_type = json_object_get_string(light_obj, "type");
	size_t			i;

	i = ~0UL;
	NODO_F(light_obj, ERRIN_N(E_INVALID_LGT, i + 1, E_IN_LINE));
	NODO_F(light_type, ERRIN_N(E_LTYPE_MISS, curr_light_i + 1, E_IN_LIGHT));
	while (max_lights > ++i)
		if (!ft_strncmp((char*)light_type, l_types[i], ft_strlen(l_types[i])))
			return (fn_lights[i](light_obj, l, curr_light_i));
	NODO_F(false, ERRIN_N(E_UNKNOWN_LGT_TYPE, curr_light_i + 1, E_IN_LIGHT));
	return (true);
}

bool		rt_parse_lights(Scene *const scene,
				JSON_Object const *const root_obj)
{
	JSON_Value const	*l_value = json_object_get_value(root_obj, "Lights");
	JSON_Array			*lights_arr;
	ssize_t				i;

	i = -1L;
	NOM_F(E_NOLIGHT, l_value);
	IFM_F(E_LARR_TYPE, JSONArray != json_value_get_type(l_value));
	NOM_F(E_NOLIGHT, lights_arr = json_value_get_array(l_value));
	NOM_F(E_NOLIGHT, scene->ins_lights = json_array_get_count(lights_arr));
	MEM(Light, scene->lights, scene->ins_lights, E_ALLOC);
	while (scene->ins_lights > ++i)
		NO_F(s_parse_current_light(json_array_get_object(lights_arr, i),
				&scene->lights[i], i));
	return (true);
}
