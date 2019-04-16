/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:47:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/16 22:40:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline bool	rt_scam(Scene *sc, string s)
{
	s += ft_skip_to_blank(s);
	ISR(*s++ != ' ', false);
	ISR(!*s || !ft_isdigit(*s), false);
	ISR(',' != *(s += ft_digits(sc->cam.pos.x = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(sc->cam.pos.y = ft_atoi(s))) || !*s++, false);
	ISR(' ' != *(s += ft_digits(sc->cam.pos.z = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(sc->cam.dir.x = ft_atoi(s))) || !*s++, false);
	ISR(',' != *(s += ft_digits(sc->cam.dir.y = ft_atoi(s))) || !*s++, false);
	ISR(*(s += ft_digits(sc->cam.dir.z = ft_atoi(s))), false);
	return (true);
}

static bool	rt_clight(Scene *sc, string s)
{
	if (sc)
	{
	}
	ft_strdel(&s);
	return (true);
}

static bool	add_parser(string line, Scene *s)
{
	const string			params[] = {FP_CAM, FP_LIGHT};
	const fn_scene_parse	fns[] = {rt_scam, rt_clight};
	bool					is_valid;
	int16_t					i;

	i = -1;
	while (2 > ++i)
		if (!ft_strncmp(line, params[i], ft_strlen(params[i])))
			is_valid = fns[i](s, line);
	ft_strdel(&line);
	return is_valid;
}

bool		rt_read_scene(Environment *env, string scene_file)
{

	const int32_t			fd = open(scene_file, O_RDONLY);
	string					temp;

	ISME(PERR, 0 >= fd, rt_free(&env), 0);
	while (0 < ft_gnl(fd, &temp))
	{
		ISM(E_ISYNTAX, !add_parser(temp, &env->s), rt_free(&env), false);
	}
	close(fd);
	return (true);
}
