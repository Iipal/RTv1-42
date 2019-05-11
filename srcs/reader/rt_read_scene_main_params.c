/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_main_params.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:32:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/11 12:07:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_scam(Scene *sc, string s, int32_t *o)
{
	(void)o;
	IFM_F(E_DCAMERA, sc->cam.is);
	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || !ft_isdigit(*s));
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

inline bool	rt_slight(Scene *sc, string s, int32_t *o)
{
	(void)o;
	IFM_F(E_DLIGHT, sc->l.is);
	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || !ft_isdigit(*s));
	IF_F(',' != *(s += ft_digits(X(sc->l.pos) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(Y(sc->l.pos) = ft_atoi(s))) || !*s++);
	IF_F(' ' != *(s += ft_digits(Z(sc->l.pos) = ft_atoi(s))) || !*s++);
	IF_F(*(s += ft_digits(sc->l.intens = ft_atoi(s))));
	if (Y(sc->l.pos) != 0.0f)
		Y(sc->l.pos) = -Y(sc->l.pos);
	IFDO(0 < sc->l.intens, sc->l.intens /= 100);
	sc->l.is = true;
	return (true);
}
