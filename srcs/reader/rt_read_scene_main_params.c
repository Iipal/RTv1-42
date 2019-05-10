/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_main_params.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:32:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/10 10:19:58 by tmaluh           ###   ########.fr       */
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
	IF_F(',' != *(s += ft_digits(sc->cam.pos[X] = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(sc->cam.pos[Y] = ft_atoi(s))) || !*s++);
	IF_F(' ' != *(s += ft_digits(sc->cam.pos[Z] = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(sc->cam.dir[X] = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(sc->cam.dir[Y] = ft_atoi(s))) || !*s++);
	IF_F(*(s += ft_digits(sc->cam.dir[Z] = -ft_atoi(s))));
	if (sc->cam.pos[Y] != 0.0f)
		sc->cam.pos[Y] = -sc->cam.pos[Y];
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
	IF_F(',' != *(s += ft_digits(sc->l.pos[X] = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(sc->l.pos[Y] = ft_atoi(s))) || !*s++);
	IF_F(' ' != *(s += ft_digits(sc->l.pos[Z] = ft_atoi(s))) || !*s++);
	IF_F(*(s += ft_digits(sc->l.intens = ft_atoi(s))));
	if (sc->l.pos[Y] != 0.0f)
		sc->l.pos[Y] = -sc->l.pos[Y];
	IFDO(0 < sc->l.intens, sc->l.intens /= 100);
	sc->l.is = true;
	return (true);
}
