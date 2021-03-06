/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_arr_to_vec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 17:49:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/09/02 21:51:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_parse_arr_to_vec(const JSON_Array *const arr,
			t_v4df *const dst,
			char const *const obj_name,
			size_t const parsing_obj_counter)
{
	size_t	i;

	i = ~0UL;
	NODO_F(arr, ERRIN_N(obj_name, parsing_obj_counter + 1, E_INVALID_ARR));
	IFDO_F(DEF_VEC_SIZE != json_array_get_count(arr),
		ERRIN_N(obj_name, parsing_obj_counter + 1UL, E_VEC_FRMT));
	while (DEF_VEC_SIZE > ++i)
	{
		IFDO_F(JSONNumber != json_value_get_type(json_array_get_value(arr, i)),
			ERRIN_N(obj_name, parsing_obj_counter + 1UL, E_VEC_FRMT));
		(*dst)[i] = json_array_get_number(arr, i);
	}
	return (true);
}
