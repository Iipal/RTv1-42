/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:23:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/09 13:59:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_scene_parse.h"

bool	rt_parse_scene(Environment *const env, char const *const scene_file)
{
	JSON_Value	*root;
	JSON_Object	*obj;

	NOM_F(E_ISYNTAX, root = json_parse_file(scene_file));
	NOM_F(E_ISYNTAX, obj = json_value_get_object(root));
	NODO_F(env->scene.is_camera_exist = rt_parse_cam(&env->scene.cam, obj),
											json_value_free(root));
	NODO_F(rt_parse_lights(&env->scene, obj), json_value_free(root));
	NODO_F(rt_parse_objects(&env->scene, obj), json_value_free(root));
	NODO_F(rt_parse_other(env, obj), json_value_free(root));
	json_value_free(root);
	return (true);
}
