/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:23:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/17 11:08:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_scene_parse.h"

inline bool	rt_parse_scene(Environment *const env, const char *const scene_file)
{
	JSON_Value	*root;
	JSON_Object	*obj;

	NOM_F(E_ISYNTAX, root = json_parse_file(scene_file));
	NOM_F(E_ISYNTAX, obj = json_value_get_object(root));
	NODO_F(env->scene.is_camera_exist
		= rt_parse_cam(&env->scene.cam, obj), json_value_free(root));
	NODO_F(rt_parse_lights(&env->scene, obj), json_value_free(root));
	NODO_F(rt_parse_objects(&env->scene, obj), json_value_free(root));
	env->scene.is_render_shadow = rt_parse_shadows(obj);
	json_value_free(root);
	return (true);
}