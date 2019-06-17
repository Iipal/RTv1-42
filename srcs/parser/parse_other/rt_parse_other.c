/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:08:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/17 12:15:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_scene_parse.h"

inline bool	rt_parse_other(Environment *const env,
				const JSON_Object *const root_obj)
{
	const bool	is_shadows = json_object_has_value(root_obj, "Shadows");
	const bool	is_aa = json_object_has_value(root_obj, "Anti-Aliasing");
	const int	shadows = json_object_get_boolean(root_obj, "Shadows");
	const int	aa = json_object_get_number(root_obj, "Anti-Aliasing");

	IFM_F(E_SHADOWS_BOOL, is_shadows && (-1 == shadows));
	IFM_F(E_AA_USELESS, is_aa && (1 >= aa));
	IFM_F(E_AA_MAX, is_aa && (8 < aa));
	IFM_F(E_AA_NUMBER, is_aa && !aa);
	env->flags.anti_aliasing = aa;
	env->flags.is_parsed_aa = is_aa;
	env->scene.is_render_shadow = is_shadows;
	return (true);
}
