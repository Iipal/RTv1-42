/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parce_array_to_vec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 17:49:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/14 19:26:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_parce_array_to_vec(const JSON_Array *const arr, __v4df *const dst)
{
	size_t	i;

	i = ~0UL;
	IFM_F(E_IN_PARAM(param_name, E_VEC_SIZE),
		DEF_VEC_SIZE != json_array_get_count(arr));
	while (DEF_VEC_SIZE > ++i)
		IFM_F(E_IN_PARAM(param_name, E_VEC_FRMT),
			JSONNumber != json_value_get_type(json_array_get_value(arr, i)));
	*dst = (__v4df){json_array_get_number(arr, 0),
					json_array_get_number(arr, 1),
					json_array_get_number(arr, 2)};
	return (true);
}
