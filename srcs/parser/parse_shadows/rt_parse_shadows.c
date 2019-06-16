/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_shadows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:08:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/16 13:57:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1_scene_parse.h"

inline bool	rt_parse_shadows(const JSON_Object *const root_obj)
{
	return (json_object_get_boolean(root_obj, "Shadows"));
}
