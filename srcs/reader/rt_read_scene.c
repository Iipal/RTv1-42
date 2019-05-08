/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:47:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/08 15:09:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_valid_saved_data(Scene *sc)
{
	int32_t	i;

	i = -1;
	IFDOR(!sc->cam.is, MSGN(E_NOCAM), false);
	IFDOR(!sc->l.is, MSGN(E_NOLIGHT), false);
	IFDOR(!u_inrange(sc->cam.dir, true, true), MSGN(E_CAMDIR), false);
	IFDOR(!u_inrange(sc->cam.pos, true, true), MSGN(E_CAMPOS), false);
	IFDOR(!u_inrange(sc->l.pos, true, true), MSGN(E_LIGHTPOS), false);
	IFDOR(.0f > sc->l.intensity || 1.0f < sc->l.intensity, MSGN(E_LINT), false);
	if (sc->ins_objs)
		while (++i < sc->ins_objs)
		{
			IFDOR(!u_inrange(OBJ(i).pos, true, true), MSGN(E_SPPOS), 0);
			IFDOR(MIN_SPR > OBJ(i).radius
				|| MAX_SPR < OBJ(i).radius, MSGN(E_SPRAD), false);
			IFDOR(MIN_SPSP > OBJ(i).spec
				|| MAX_SPSP < OBJ(i).spec, MSGN(E_SPSPEC), false);
		}
	return (true);
}

static bool	add_parser(Scene *sc, string *str, int16_t nline, int32_t *o)
{
	const fns_parse	fns[] = {rt_scam, rt_slight, rt_ssphere};
	const string	params[] = {FP_CAM, FP_LIGHT, FP_SPHERE};
	bool			is_valid_data;
	bool			is_known_obj_type;
	int16_t			i;

	i = -1;
	is_valid_data = false;
	is_known_obj_type = false;
	while ((sizeof(params) / sizeof(*params)) > (size_t)++i)
		if (!ft_strncmp(*str, params[i], ft_strlen(params[i]))
		&& (is_known_obj_type = true))
			is_valid_data = fns[i](sc, *str, o);
	IFDOM(E_OBJ, !is_known_obj_type, is_valid_data = false);
	NOTIS(E_ISYNTAX, is_valid_data, ERRAT(*str, nline), false);
	ft_strdel(str);
	return (is_valid_data);
}

static bool	add_valid_objs_counter(int32_t *fd, Scene *s, string file)
{
	string			temp;
	const string	objs[] = {FP_SPHERE};
	const int32_t	max_objs = (sizeof(objs) / sizeof(*objs));
	int32_t			i;

	s->ins_objs = 0;
	while (0 < ft_gnl(*fd, &temp) && (i = -1))
	{
		while (++i < max_objs)
			if (!ft_strncmp(temp, objs[i], ft_strlen(objs[i])))
			{
				++s->ins_objs;
				break ;
			}
		ft_strdel(&temp);
	}
	close(*fd);
	IFDO(s->ins_objs, MEM(Object, s->objs, s->ins_objs, E_ALLOC));
	ISME(PERR, 0 > (*fd = open(file, O_RDONLY)), (void)0, false);
	return (true);
}

bool		rt_read_scene(Environment *env, string scene_file)
{
	int32_t		fd;
	string		temp;
	uint16_t	nline;
	int32_t		obj_counter;

	nline = 0;
	obj_counter = 0;
	ISME(PERR, 0 > (fd = open(scene_file, O_RDONLY)), rt_free(&env), false);
	IFDOR(!add_valid_objs_counter(&fd, &env->s, scene_file), rt_free(&env), 0);
	while (0 < ft_gnl(fd, &temp))
		IFDOR(!add_parser(&env->s, &temp, ++nline, &obj_counter),
			rt_free(&env), false);
	NOTIS(E_EFILE, nline, rt_free(&env), false);
	close(fd);
	NOTIS_F(add_valid_saved_data(&env->s));
	return (true);
}
