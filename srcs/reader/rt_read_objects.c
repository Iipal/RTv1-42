/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:31:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/20 12:47:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_ssphere(Scene *sc, string s, int32_t *o)
{
	Uint32	clr;

	s += ft_skip_to_blank(s);
	ISR(*s++ != ' ', false);
	ISR(!*s || !ft_isdigit(*s), false);
	ISR(',' != *(s += ft_digits(OBJ(*o).pos.x = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(OBJ(*o).pos.y = ft_atoi(s))) || !*s++, false);
	ISR(' ' != *(s += ft_digits(OBJ(*o).pos.z = ft_atoi(s))) || !*s++, false);
	ISR(*s++ != '0' || *s++ != 'x', false);
	NOTIS_F(clr = ft_atoi_base(s, 16));
	ISR(' ' != *(s += ft_skip_to_blank(s)) || !*s++, false);
	ISR(' ' != *(s += ft_digits(OBJ(*o).radius = ft_atoi(s))) || !*s++, false);
	ISR(*(s += ft_digits(OBJ(*o).spec = ft_atoi(s))), false);
	OBJ(*o).pos.y = -OBJ(*o).pos.y;
	OBJ(*o).clr = (Color){clr >> 16, (clr >> 8) & 0xff, clr & 0xff};
	++(*o);
	return (true);
}
