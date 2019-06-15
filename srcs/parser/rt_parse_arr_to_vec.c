/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_arr_to_vec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 17:49:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/15 12:56:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_parse_arr_to_vec(const JSON_Array *const arr,
			__v4df *const dst,
			const char *const obj_name,
			const size_t parsing_obj_counter)
{
	size_t	i;

	i = ~0UL;
	// (void)obj_name;
	IFDO_F(DEF_VEC_SIZE != json_array_get_count(arr),
		ERRIN_N(obj_name, parsing_obj_counter + 1, E_VEC_FRMT));
	while (DEF_VEC_SIZE > ++i)
		IFDO_F(JSONNumber != json_value_get_type(json_array_get_value(arr, i)),
			ERRIN_N(obj_name, parsing_obj_counter + 1, E_VEC_FRMT));
	*dst = (__v4df){json_array_get_number(arr, 0),
					json_array_get_number(arr, 1),
					json_array_get_number(arr, 2)};
	return (true);
}
