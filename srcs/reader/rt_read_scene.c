/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:47:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 17:19:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_valid_saved_data(Scene *sc)
{
	size_t	i;

	NOM_F(E_NOCAM, sc->cam.is);
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

static bool	add_parser(Scene *sc, string *str, t_pfhelp *pfh)
{
	const fns_parse	fns[] = {rt_ssphere, rt_splane, rt_scylinder};
	const string	params[] = {FP_SPHERE, FP_PLANE, FP_CYLINDER};
	bool			is_valid_data;
	bool			is_known;
	size_t			i;

	i = ~0L;
	++pfh->nline;
	is_known = false;
	is_valid_data = false;
	IFR(**str == '#', true);
	if (!ft_strncmp(*str, FP_LIGHT, ft_strlen(FP_LIGHT)) && (is_known = true))
		is_valid_data = rt_slight(&sc->l[pfh->light_counter++], *str);
	else if (!ft_strncmp(*str, FP_CAM, ft_strlen(FP_CAM)) && (is_known = true))
		is_valid_data = rt_scam(&sc->cam, *str);
	else
		while ((sizeof(params) / sizeof(*params)) > ++i)
			if (!ft_strncmp(*str, params[i], ft_strlen(params[i]))
			&& (is_known = true))
				is_valid_data = fns[i](&sc->objs[pfh->obj_counter++], *str);
	IFDOM(E_OBJ, !is_known, is_valid_data = false);
	NO(E_ISYNTAX, is_valid_data, ERRAT(*str, pfh->nline), false);
	ft_strdel(str);
	return (is_valid_data);
}

static bool	add_valid_objs_counter(int32_t *fd, Scene *s, const string file)
{
	string			temp;

	while (0 < ft_gnl(*fd, &temp))
	{
		if (*temp == '#')
			NULL;
		else if (!ft_strncmp(temp, FP_LIGHT, ft_strlen(FP_LIGHT)))
			++s->ins_l;
		else if (ft_is_one_of_str(temp, true, FP_MAX_OBJS,
					FP_SPHERE, FP_CONE, FP_CYLINDER, FP_PLANE))
			++s->ins_objs;
		ft_strdel(&temp);
	}
	close(*fd);
	NOM_F(E_NOOBJS, s->ins_objs);
	NOM_F(E_NOLIGHT, s->ins_l);
	IFM_F(E_MLIGHTS, MAX_LIGHTS < s->ins_l);
	MEM(Object, s->objs, s->ins_objs, E_ALLOC);
	MEM(Light, s->l, s->ins_l, E_ALLOC);
	IFME(PERR, 0 > (*fd = open(file, O_RDONLY)), (void)0, false);
	return (true);
}

bool		rt_read_scene(Environment *env, string scene_file)
{
	int32_t		fd;
	string		tmp;
	t_pfhelp	pfh;

	C(t_pfhelp, &pfh, 1);
	IFME(PERR, 0 > (fd = open(scene_file, O_RDONLY)), rt_free(&env), false);
	NODO_F(add_valid_objs_counter(&fd, &env->s, scene_file), rt_free(&env));
	while (0 < ft_gnl(fd, &tmp))
		NODO_F(add_parser(&env->s, &tmp, &pfh), rt_free(&env));
	close(fd);
	NO(E_EFILE, pfh.nline, rt_free(&env), false);
	NO_F(add_valid_saved_data(&env->s));
	return (true);
}
