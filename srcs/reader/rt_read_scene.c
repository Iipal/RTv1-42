/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:47:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/18 16:20:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_valid_saved_data(Scene *sc)
{
	IFDOR(!sc->cam.is, MSGN(E_NOCAM), false);
	IFDOR(!sc->l.is, MSGN(E_NOLIGHT), false);
	IFDOR(!u_inrange(sc->cam.dir, true, true), MSGN(E_CAMDIR), false);
	IFDOR(!u_inrange(sc->cam.pos, true, true), MSGN(E_CAMPOS), false);
	IFDOR(!u_inrange(sc->l.pos, true, true), MSGN(E_LIGHTPOS), false);
	IFDOR(.0f > sc->l.intensity || 1.0f < sc->l.intensity, MSGN(E_LINT), false);
	if (!sc->sp.is)
	{
		IFDOR(!u_inrange(sc->sp.pos, true, true), MSGN(E_SPPOS), false);
		IFDOR(0 > sc->sp.radius || 50 < sc->sp.radius, MSGN(E_SPRAD), false);
		IFDOR(0 > sc->sp.spec || 50 < sc->sp.spec, MSGN(E_SPSPEC), false);
	}
	return (true);
}

static bool	add_parser(Scene *sc, string *str, int16_t nline)
{
	const fn_scene_parse	fns[] = {rt_scam, rt_slight, rt_ssphere};
	const string			params[] = {FP_CAM, FP_LIGHT, FP_SPHERE};
	bool					is_valid;
	int16_t					i;

	i = -1;
	is_valid = false;
	while ((sizeof(fns) / sizeof(*fns)) > (size_t)++i)
		if (!ft_strncmp(*str, params[i], ft_strlen(params[i])))
			is_valid = fns[i](sc, *str);
	IFDOR(!is_valid, MSGN(E_ISYNTAX); ERRAT(nline, *str), false);
	ft_strdel(str);
	return (is_valid);
}

bool		rt_read_scene(Environment *env, string scene_file)
{
	const int32_t	fd = open(scene_file, O_RDONLY);
	string			temp;
	int16_t			nline;

	nline = 1;
	ISME(PERR, 0 >= fd, rt_free(&env), 0);
	while (0 < ft_gnl(fd, &temp))
		IFDOR(!add_parser(&env->s, &temp, nline++), rt_free(&env), false);
	close(fd);
	NOTIS_F(add_valid_saved_data(&env->s));
	return (true);
}
