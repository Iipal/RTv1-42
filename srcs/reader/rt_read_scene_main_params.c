/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_main_params.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:32:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/12 22:02:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_scam(Scene *sc, string s, size_t *o)
{
	(void)o;
	IFM_F(E_DCAMERA, sc->cam.is);
	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || (!ft_isdigit(*s) && *s != '-'));
	IF_F(',' != *(s += ft_digits(X(sc->cam.pos) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(Y(sc->cam.pos) = ft_atoi(s))) || !*s++);
	IF_F(' ' != *(s += ft_digits(Z(sc->cam.pos) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(X(sc->cam.dir) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(Y(sc->cam.dir) = ft_atoi(s))) || !*s++);
	IF_F(*(s += ft_digits(Z(sc->cam.dir) = -ft_atoi(s))));
	if (Y(sc->cam.pos) != 0.0f)
		Y(sc->cam.pos) = -Y(sc->cam.pos);
	sc->cam.is = true;
	return (true);
}

inline bool	rt_slight(Scene *sc, string s, size_t *o)
{
	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || (!ft_isdigit(*s) && *s != '-'));
	IF_F(',' != *(s += ft_digits(X(sc->l[*o].pos) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(Y(sc->l[*o].pos) = ft_atoi(s))) || !*s++);
	IF_F(' ' != *(s += ft_digits(Z(sc->l[*o].pos) = ft_atoi(s))) || !*s++);
	IF_F(*(s += ft_digits(sc->l[*o].intens = ft_atoi(s))));
	if (Y(sc->l[*o].pos) != 0.0f)
		Y(sc->l[*o].pos) = -Y(sc->l[*o].pos);
	IFDO(0 < sc->l[*o].intens, sc->l[*o].intens /= 100);
	++(*o);
	return (true);
}
