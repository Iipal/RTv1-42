/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 17:34:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/14 19:19:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_parse_cam(Camera *const camera, JSON_Object *root_obj)
{
	JSON_Object	*obj;

	NOM_F(E_NOCAM, obj = json_object_get_object(root_obj, FP_CAM));
	NOM_F(W_MISS_PARAM("position", FP_CAM),
		json_object_has_value_of_type(obj, "position", JSONArray));
	IF_F(rt_parce_array_to_vec(
		json_object_get_array(obj, "position"), &camera->pos, "Camera"));
	NOM_F(W_MISS_PARAM("rotation", FP_CAM),
		json_object_has_value_of_type(obj, "rotation", JSONArray));
	IF_F(rt_parce_array_to_vec(
		json_object_get_array(obj, "rotation"), &camera->dir, "Camera"));
	return (true);
}
