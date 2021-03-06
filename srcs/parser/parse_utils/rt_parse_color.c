/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:09:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/06 13:26:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_parse_color(char *hex_str, Color *const dst,
			size_t const parsing_obj_counter)
{
	IFDO_F(ft_strncmp(hex_str, "0x", 2UL),
		ERRIN_N(E_OCLR_0X_MISS, parsing_obj_counter + 1, E_IN_OBJ));
	hex_str += 2UL;
	NODO_F(ft_ishex_str(hex_str),
		ERRIN_N(E_INVALID_HCLR, parsing_obj_counter + 1, E_IN_OBJ));
	IFDO_F(MAX_HEX_SPECTRUM_LENGHT < ft_strlen(hex_str),
		ERRIN_N(E_OCLR_SPECTR, parsing_obj_counter + 1, E_IN_OBJ));
	NODO_F((*dst).hex = ft_atoi_base(hex_str, 16),
		ERRIN_N(E_INVALID_CLR, parsing_obj_counter + 1, E_IN_OBJ));
	return (true);
}
