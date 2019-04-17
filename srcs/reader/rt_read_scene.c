/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:47:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/17 13:35:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static bool	add_valid_saved_data(Scene *sc)
{
	if (!sc)
		return (false);
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

	nline = 1;
	ISME(PERR, 0 >= fd, rt_free(&env), 0);
	while (0 < ft_gnl(fd, &temp))
		ISM(E_ISYNTAX, !add_parser(&env->s, &temp, nline++),
			rt_free(&env), false);
	close(fd);
	add_valid_saved_data(&env->s);
	return (true);
}
