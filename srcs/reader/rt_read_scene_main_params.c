/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_main_params.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:32:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/10 19:52:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_scam(Camera *const restrict cam, string s)
{
	IFM_F(E_DCAMERA, cam->is);
	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || (!ft_isdigit(*s) && *s != '-'));
	NO_F(rt_read_vec(&s, &cam->pos));
	X(cam->dir) = ft_atof(s);
	IF_F(',' != *(s += ft_fdigits_str(s)) || !*s++);
	Y(cam->dir) = ft_atof(s);
	IF_F(',' != *(s += ft_fdigits_str(s)) || !*s++);
	Z(cam->dir) = ft_atof(s);
	IF_F(*(s += ft_fdigits_str(s)));
	if (Y(cam->pos) != 0.0f)
		Y(cam->pos) = -Y(cam->pos);
	cam->is = true;
	return (true);
}

inline bool	rt_slight(Light *restrict const l, string s)
{
	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || (!ft_isdigit(*s) && *s != '-'));
	NO_F(rt_read_vec(&s, &l->pos));
	NO_F(rt_read_vec(&s, &l->dir));
	l->intens = ft_atof(s);
	IF_F(*(s += ft_fdigits_str(s)));
	if (Y(l->pos) != 0.0f)
		Y(l->pos) = -Y(l->pos);
	IFDO(0.0f < l->intens, l->intens /= 100.0f);
	return (true);
}
