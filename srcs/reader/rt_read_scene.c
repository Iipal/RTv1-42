/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:47:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/12 10:34:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_valid_saved_data(Scene *sc)
{
	size_t	i;

	NOM_F(E_NOCAM, sc->cam.is);
	NOM_F(E_NOOBJS, sc->ins_objs);
	NOM_F(E_CAMDIR, u_inrange(sc->cam.dir, true, true));
	NOM_F(E_CAMPOS, u_inrange(sc->cam.pos, true, true));
	i = ~0L;
	while (sc->ins_l > ++i)
	{
		NOM_F(E_LIGHTPOS, u_inrange(sc->l[i].pos, true, true));
		IFM_F(E_LINTENSE, .0f > sc->l[i].intens || 1.0f < sc->l[i].intens);
	}
	i = ~0L;
	while (sc->ins_objs > ++i)
	{
		NOM_F(E_SPPOS, u_inrange(sc->objs[i].pos, true, true));
		IFM_F(E_SPRAD, MIN_SPR > sc->objs[i].radius
			|| MAX_SPR < sc->objs[i].radius);
		IFM_F(E_SPSPEC, MIN_SPSP > sc->objs[i].spec
			|| MAX_SPSP < sc->objs[i].spec);
	}
	return (true);
}

static bool	add_parser(Scene *sc, string *str,
	int16_t nline, size_t *o, size_t *l)
{
	const fns_parse	fns[] = {rt_scam, rt_ssphere};
	const string	params[] = {FP_CAM, FP_SPHERE};
	bool			is_valid_data;
	bool			is_known_obj_type;
	size_t			i;

	i = ~0L;
	is_valid_data = false;
	is_known_obj_type = false;
	if (!ft_strncmp(*str, FP_LIGHT, ft_strlen(FP_LIGHT))
	&& (is_known_obj_type = true))
		is_valid_data = rt_slight(sc, *str, l);
	else
		while ((sizeof(params) / sizeof(*params)) > ++i)
			if (!ft_strncmp(*str, params[i], ft_strlen(params[i]))
			&& (is_known_obj_type = true))
				is_valid_data = fns[i](sc, *str, o);
	IFDOM(E_OBJ, !is_known_obj_type, is_valid_data = false);
	NO(E_ISYNTAX, is_valid_data, ERRAT(*str, nline), false);
	ft_strdel(str);
	return (is_valid_data);
}

static bool	add_valid_objs_counter(int32_t *fd, Scene *s, const string file)
{
	const string	objs[] = {FP_SPHERE};
	const int32_t	max_objs = (sizeof(objs) / sizeof(*objs));
	string			temp;
	int32_t			i;

	while (0 < ft_gnl(*fd, &temp) && (i = -1))
	{
		if (!ft_strncmp(temp, FP_LIGHT, ft_strlen(FP_LIGHT)))
			++s->ins_l;
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
	IFDO(s->ins_l, MEM(Light, s->l, s->ins_l, E_ALLOC));
	IFDOMR(PERR, 0 > (*fd = open(file, O_RDONLY)), (void)0, false);
	return (true);
}

bool		rt_read_scene(Environment *env, string scene_file)
{
	int32_t		fd;
	string		tmp;
	uint16_t	nline;
	size_t		obj_counter;
	size_t		light_counter;

	nline = 0;
	obj_counter = 0;
	light_counter = 0;
	IFDOMR(PERR, 0 > (fd = open(scene_file, O_RDONLY)), rt_free(&env), false);
	NODO_F(add_valid_objs_counter(&fd, &env->s, scene_file), rt_free(&env));
	while (0 < ft_gnl(fd, &tmp))
		NODO_F(add_parser(&env->s, &tmp, ++nline, &obj_counter, &light_counter),
			rt_free(&env));
	close(fd);
	NO(E_EFILE, nline, rt_free(&env), false);
	NO_F(add_valid_saved_data(&env->s));
	return (true);
}
