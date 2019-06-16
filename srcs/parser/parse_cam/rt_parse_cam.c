/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 17:34:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/16 14:03:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_scene_parse.h"

inline bool	rt_parse_cam(Camera *const camera,
				const JSON_Object *const root_obj)
{
	const JSON_Object	*obj_cam = json_object_get_object(root_obj, "Camera");

	NOM_F(E_NOCAM, obj_cam);
	NODO_F(json_object_has_value_of_type(obj_cam, "position", JSONArray),
		ERRIN(E_CPOS_MISS, E_IN_CAM));
	NODO_F(json_object_has_value_of_type(obj_cam, "rotation", JSONArray),
		ERRIN(E_CROT_MISS, E_IN_CAM));
	NO_F(rt_parse_arr_to_vec(
		json_object_get_array(obj_cam, "position"), &camera->pos, "Camera", 0));
	NO_F(rt_parse_arr_to_vec(
		json_object_get_array(obj_cam, "rotation"), &camera->dir, "Camera", 0));
	return (camera->is = true);
}
