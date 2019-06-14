/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:23:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/14 18:19:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_parse_scene(Environment *env, const char *const scene_file)
{
	JSON_Value	*root;
	JSON_Object	*obj;

	NOM_F(E_ISYNTAX, root = json_parse_file(scene_file));
	obj = json_value_get_object(root);
	rt_parse_cam(&env->scene.cam, obj);
	json_value_free(root);
	return (true);
}
