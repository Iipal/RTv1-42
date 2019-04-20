/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_main_params.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:32:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/20 12:24:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_scam(Scene *sc, string s, int32_t *o)
{
	(void)o;
	IFDOR(sc->cam.is, MSGN(E_DUP), false);
	s += ft_skip_to_blank(s);
	ISR(*s++ != ' ', false);
	ISR(!*s || !ft_isdigit(*s), false);
	ISR(',' != *(s += ft_digits(sc->cam.pos.x = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(sc->cam.pos.y = ft_atoi(s))) || !*s++, false);
	ISR(' ' != *(s += ft_digits(sc->cam.pos.z = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(sc->cam.dir.x = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(sc->cam.dir.y = ft_atoi(s))) || !*s++, false);
	ISR(*(s += ft_digits(sc->cam.dir.z = -ft_atoi(s))), false);
	sc->cam.pos.y = -sc->cam.pos.y;
	sc->cam.is = true;
	return (true);
}

inline bool	rt_slight(Scene *sc, string s, int32_t *o)
{
	(void)o;
	IFDOR(sc->l.is, MSGN(E_DUP), false);
	s += ft_skip_to_blank(s);
	ISR(*s++ != ' ', false);
	ISR(!*s || !ft_isdigit(*s), false);
	ISR(',' != *(s += ft_digits(sc->l.pos.x = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(sc->l.pos.y = ft_atoi(s))) || !*s++, false);
	ISR(' ' != *(s += ft_digits(sc->l.pos.z = ft_atoi(s))) || !*s++, false);
	ISR(*(s += ft_digits(sc->l.intensity = ft_atoi(s))), false);
	sc->l.pos.y = -sc->l.pos.y;
	sc->l.intensity /= 100;
	sc->l.is = true;
	return (true);
}
