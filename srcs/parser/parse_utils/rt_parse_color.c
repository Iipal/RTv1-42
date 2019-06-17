/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:09:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/17 12:31:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_parse_color(string hex_str, Color *const dst,
				const size_t parsing_obj_counter)
{
	IFDO_F(ft_strncmp(hex_str, "0x", ft_strlen("0x")),
		ERRIN_N(E_OCLR_0X_MISS, parsing_obj_counter + 1, E_IN_OBJ));
	hex_str += ft_strlen("0x");
	NODO_F(ft_ishex_str(hex_str),
		ERRIN_N(E_INVALID_HCLR, parsing_obj_counter + 1, E_IN_OBJ));
	IFDO_F(MAX_HEX_SPECTRUM_LENGHT < ft_strlen(hex_str),
		ERRIN_N(E_OCLR_SPECTR, parsing_obj_counter + 1, E_IN_OBJ));
	NODO_F((*dst).hex = ft_atoi_base(hex_str, 16),
		ERRIN_N(E_INVALID_CLR, parsing_obj_counter + 1, E_IN_OBJ));
	return (true);
}
