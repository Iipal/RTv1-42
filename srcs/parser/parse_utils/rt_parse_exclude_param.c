/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_exclude_param.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 22:55:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/15 23:01:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_scene_parse.h"

bool	rt_parse_exclude_param(const JSON_Object *const obj, string param)
{
	JSON_Value_Type	i;

	i = JSONError;
	while (JSONBoolean >= ++i)
		if (json_object_has_value_of_type(obj, param, i))
			return (false);
	return (true);
}
