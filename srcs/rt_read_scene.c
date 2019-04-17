/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:47:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/17 12:40:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	rt_scam(Scene *sc, string s)
{
	IFDOR(sc->cam.is, MSGN(E_DUP), false);
	s += ft_skip_to_blank(s);
	ISR(*s++ != ' ', false);
	ISR(!*s || !ft_isdigit(*s), false);
	ISR(',' != *(s += ft_digits(sc->cam.pos.x = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(sc->cam.pos.y = ft_atoi(s))) || !*s++, false);
	ISR(' ' != *(s += ft_digits(sc->cam.pos.z = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(sc->cam.dir.x = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(sc->cam.dir.y = ft_atoi(s))) || !*s++, false);
	ISR(*(s += ft_digits(sc->cam.dir.z = ft_atoi(s))), false);
	sc->cam.is = true;
	return (true);
}

static bool	rt_clight(Scene *sc, string s)
{
	IFDOR(sc->l.is, MSGN(E_DUP), false);
	s += ft_skip_to_blank(s);
	ISR(*s++ != ' ', false);
	ISR(!*s || !ft_isdigit(*s), false);
	ISR(',' != *(s += ft_digits(sc->l.pos.x = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(sc->l.pos.y = ft_atoi(s))) || !*s++, false);
	ISR(' ' != *(s += ft_digits(sc->l.pos.z = ft_atoi(s))) || !*s++, false);
	ISR(*(s += ft_digits(sc->l.intense = ft_atoi(s))), false);
	sc->l.intense /= 100;
	sc->l.is = true;
	return (true);
}

static bool	rt_csphere(Scene *sc, string s)
{
	IFDOR(sc->sp.is, MSGN(E_DUP), false);
	s += ft_skip_to_blank(s);
	ISR(*s++ != ' ', false);
	ISR(!*s || !ft_isdigit(*s), false);
	ISR(',' != *(s += ft_digits(sc->sp.pos.x = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(sc->sp.pos.y = ft_atoi(s))) || !*s++, false);
	ISR(' ' != *(s += ft_digits(sc->sp.pos.z = ft_atoi(s))) || !*s++, false);
	ISR(*s++ != '0' || *s++ != 'x', false);
	NOTIS_F(sc->sp.clr = ft_atoi_base(s, 16));
	ISR(' ' != *(s += ft_skip_to_blank(s)) || !*s++, false);
	ISR(' ' != *(s += ft_digits(sc->sp.radius = ft_atoi(s))) || !*s++, false);
	ISR(*(s += ft_digits(sc->sp.spec = ft_atoi(s))), false);
	sc->sp.is = true;
	return (true);
}

static bool	add_parser(Scene *sc, string *str, int16_t nline)
{
	const fn_scene_parse	fns[] = {rt_scam, rt_clight, rt_csphere};
	const string			params[] = {FP_CAM, FP_LIGHT, FP_SPHERE};
	bool					is_valid;
	int16_t					i;

	i = -1;
	is_valid = false;
	while ((sizeof(fns) / sizeof(*fns)) > (size_t)++i)
		if (!ft_strncmp(*str, params[i], ft_strlen(params[i])))
			is_valid = fns[i](sc, *str);
	if (false == is_valid)
		ERRAT(nline, *str);
	ft_strdel(str);
	return (is_valid);
}

bool		rt_read_scene(Environment *env, string scene_file)
{
	const int32_t	fd = open(scene_file, O_RDONLY);
	string			temp;
	int16_t			nline;

	nline = 0;
	ISME(PERR, 0 >= fd, rt_free(&env), 0);
	while (0 < ft_gnl(fd, &temp))
		ISM(E_ISYNTAX, !add_parser(&env->s, &temp, nline++),
			rt_free(&env), false);
	close(fd);
	return (true);
}
