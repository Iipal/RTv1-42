/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:08:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/19 13:43:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_parse_other(Environment *const env,
			JSON_Object const *const root_obj)
{
	bool const	is_shadows = json_object_has_value(root_obj, "Shadows");
	bool const	is_aa = json_object_has_value(root_obj, "Anti-Aliasing");
	int const	shadows = json_object_get_boolean(root_obj, "Shadows");
	int const	aa = json_object_get_number(root_obj, "Anti-Aliasing");
	int const	al = json_object_get_number(root_obj, "Ambient light");

	IFM_F(E_SHADOWS_BOOL, is_shadows && (-1 == shadows));
	IFM_F(E_AA_USELESS, is_aa && (1 >= aa));
	IFM_F(E_AA_MAX, is_aa && (8 < aa));
	IFM_F(E_AA_NUMBER, is_aa && !aa);
	env->flags.anti_aliasing = aa;
	env->flags.ambient_light = (0 >= al) ? 100 : al;
	SET_BIT(g_flags, F_BIT_AA);
	SET_BIT(g_flags, F_BIT_AL);
	SET_BIT(g_flags, F_BIT_SHADOWS);
	return (true);
}
