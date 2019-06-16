/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 17:34:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/16 11:08:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_parse_cam(Camera *const camera, JSON_Object *root_obj)
{
	JSON_Object	*obj;

	IFM_F(E_DCAMERA, camera->is);
	NOM_F(E_NOCAM, obj = json_object_get_object(root_obj, "Camera"));
	NOM_F(W_MISS_PARAM("position", "Camera"),
		json_object_has_value_of_type(obj, "position", JSONArray));
	NO_F(rt_parse_arr_to_vec(
		json_object_get_array(obj, "position"), &camera->pos, "Camera", 0));
	NOM_F(W_MISS_PARAM("rotation", "Camera"),
		json_object_has_value_of_type(obj, "rotation", JSONArray));
	NO_F(rt_parse_arr_to_vec(
		json_object_get_array(obj, "rotation"), &camera->dir, "Camera", 0));
	return (camera->is = true);
}
