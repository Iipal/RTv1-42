/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:47:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/07 18:54:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_parser(Scene *const sc, string *str,
				t_pfhelp *const pfh)
{
	const t_fn_sparse	fns[] = {rt_ssphere, rt_scone, rt_splane, rt_scylinder};
	const string		objs[] = {FP_SPHERE, FP_CONE, FP_PLANE, FP_CYLINDER};
	bool				data;
	bool				is;
	size_t				i;

	i = ~0L;
	++pfh->nline;
	is = false;
	data = false;
	IFR(**str == '#', true);
	if (!ft_strncmp(*str, FP_SHADOWS, ft_strlen(FP_SHADOWS)) && (is = true))
		data = true;
	else if (!ft_strncmp(*str, FP_LIGHT, ft_strlen(FP_LIGHT)) && (is = true))
		data = rt_slight(&sc->lights[pfh->light_counter++], *str);
	else if (!ft_strncmp(*str, FP_CAM, ft_strlen(FP_CAM)) && (is = true))
		data = rt_scam(&sc->cam, *str);
	else
		while (max_objs > ++i)
			if (!ft_strncmp(*str, objs[i], ft_strlen(objs[i])) && (is = true))
				data = fns[i](&sc->objs[pfh->obj_counter++], *str);
	IFDOM(E_OBJ, !is, data = false);
	IFDOMR(E_ISYNTAX, !data, ERRIN_N(*str, pfh->nline, E_IN_LINE), false);
	ft_strdel(str);
	return (data);
}

static bool	add_valid_objs_counter(int32_t *const fd,
				Scene *const sc, const char *const file)
{
	string			temp;

	while (0 < ft_gnl(*fd, &temp))
	{
		if (*temp != '#')
		{
			if (!ft_strncmp(temp, FP_LIGHT, ft_strlen(FP_LIGHT)))
				++sc->ins_lights;
			else if (ft_is_one_of_str(temp, true, FP_MAX_OBJS,
						FP_SPHERE, FP_CONE, FP_CYLINDER, FP_PLANE))
				++sc->ins_objs;
			else if (!ft_strncmp(temp, FP_SHADOWS, ft_strlen(FP_SHADOWS)))
				sc->is_render_shadow = true;
		}
		ft_strdel(&temp);
	}
	close(*fd);
	NOM_F(E_NOOBJS, sc->ins_objs);
	NOM_F(E_NOLIGHT, sc->ins_lights);
	IFM_F(E_MLIGHTS, MAX_LIGHTS < sc->ins_lights);
	MEM(Object, sc->objs, sc->ins_objs, E_ALLOC);
	MEM(Light, sc->lights, sc->ins_lights, E_ALLOC);
	IFME(PERR, 0 > (*fd = open(file, O_RDONLY)), (void)0, false);
	return (true);
}

bool		rt_read_scene(Environment *restrict env,
					const char *const scene_file)
{
	int32_t		fd;
	string		tmp;
	t_pfhelp	pfh;

	ZERO(t_pfhelp, &pfh, 1);
	IFME(PERR, 0 > (fd = open(scene_file, O_RDONLY)), rt_free(&env), false);
	NODO_F(add_valid_objs_counter(&fd, &env->scene, scene_file), rt_free(&env));
	while (0 < ft_gnl(fd, &tmp))
		NODO_F(add_parser(&env->scene, &tmp, &pfh), rt_free(&env));
	close(fd);
	NO(E_EFILE, pfh.nline, rt_free(&env), false);
	NODO_F(rt_valid_readed_data(&env->scene), rt_free(&env));
	return (true);
}
