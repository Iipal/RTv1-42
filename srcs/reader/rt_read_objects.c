/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:31:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/19 23:47:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_ssphere(Scene *sc, string s)
{
	Uint32	clr;

	IFDOR(sc->sp.is, MSGN(E_DUP), false);
	s += ft_skip_to_blank(s);
	ISR(*s++ != ' ', false);
	ISR(!*s || !ft_isdigit(*s), false);
	ISR(',' != *(s += ft_digits(sc->sp.pos.x = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(sc->sp.pos.y = ft_atoi(s))) || !*s++, false);
	ISR(' ' != *(s += ft_digits(sc->sp.pos.z = ft_atoi(s))) || !*s++, false);
	ISR(*s++ != '0' || *s++ != 'x', false);
	NOTIS_F(clr = ft_atoi_base(s, 16));
	ISR(' ' != *(s += ft_skip_to_blank(s)) || !*s++, false);
	ISR(' ' != *(s += ft_digits(sc->sp.radius = ft_atoi(s))) || !*s++, false);
	ISR(*(s += ft_digits(sc->sp.spec = ft_atoi(s))), false);
	sc->sp.pos.y = -sc->sp.pos.y;
	sc->sp.clr = (Color){clr >> 16, (clr >> 8) & 0xff, clr & 0xff};
	sc->sp.is = true;
	return (true);
}
