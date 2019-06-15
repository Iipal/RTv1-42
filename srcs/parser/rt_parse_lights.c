/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_lights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 09:47:24 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/15 13:06:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_parse_current_light(JSON_Object *light_obj,
				Light *const l,
				const size_t curr_light)
{
	const t_fn_lght	fn_lights[] = {rt_parse_point_light, rt_parse_dir_light};
	const string	available_light_types[] = {LT_POINT, LT_DIRECT};
	const char		*light_type = json_object_get_string(light_obj, "type");
	size_t			i;

	i = ~0ULL;
	NODO_F(light_type, ERRIN_N(E_LIGHTYPE, curr_light + 1, E_IN_LIGHT));
	while (MAX_LT > ++i)
		if (!ft_strncmp((string)light_type, available_light_types[i],
			ft_strlen(available_light_types[i])))
			return (fn_lights[i](light_obj, l, curr_light));
	NODO_F(false, ERRIN_N(E_INVALID_LT, curr_light + 1, E_IN_LIGHT));
	return (true);
}

bool		rt_parse_lights(Scene *const scene,
				JSON_Object *root_obj)
{
	JSON_Value	*lights_value;
	JSON_Array	*lights_arr;
	JSON_Object	*light_obj;
	size_t		i;

	i = ~0ULL;
	NOM_F(E_NOLIGHT, lights_value = json_object_get_value(root_obj, "Lights"));
	IFM_F(ERR "Invalid lights array type.",
		JSONArray != json_value_get_type(lights_value));
	NOM_F(E_NOLIGHT, lights_arr = json_value_get_array(lights_value));
	NOM_F(E_NOLIGHT, scene->ins_lights = json_array_get_count(lights_arr));
	IFM_F(E_MLIGHTS, MAX_LIGHTS < scene->ins_lights);
	MEM(Light, scene->lights, scene->ins_lights, E_ALLOC);
	while (scene->ins_lights > ++i)
	{
		NOM_F(ERR "Inavlid light object",
			light_obj = json_array_get_object(lights_arr, i));
		NO_F(add_parse_current_light(light_obj, &scene->lights[i], i));
	}
	return (true);
}
