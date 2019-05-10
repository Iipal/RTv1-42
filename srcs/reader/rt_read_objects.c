/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:31:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/10 10:19:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_ssphere(Scene *sc, string s, int32_t *o)
{
	Uint32	clr;

	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || ('-' != *s && !ft_isdigit(*s)));
	IF_F(',' != *(s += ft_digits(sc->objs[*o].pos[X] = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(sc->objs[*o].pos[Y] = ft_atoi(s))) || !*s++);
	IF_F(' ' != *(s += ft_digits(sc->objs[*o].pos[Z] = ft_atoi(s))) || !*s++);
	IF_F(*s++ != '0' || *s++ != 'x');
	NO_F(clr = ft_atoi_base(s, 16));
	IF_F(' ' != *(s += ft_skip_to_blank(s)) || !*s++);
	IF_F(' ' != *(s += ft_digits(sc->objs[*o].radius = ft_atoi(s))) || !*s++);
	IF_F(*(s += ft_digits(sc->objs[*o].spec = ft_atoi(s))));
	if (sc->objs[*o].pos[Y] != 0.0f)
		sc->objs[*o].pos[Y] = -sc->objs[*o].pos[Y];
	sc->objs[*o].clr = (Color){clr >> 16, (clr >> 8) & 0xff, clr & 0xff};
	sc->objs[*o].type = sphere;
	++(*o);
	return (true);
}
