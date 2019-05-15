/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_scene_main_params.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:32:10 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/15 18:19:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_scam(Camera *cam, string s)
{
	IFM_F(E_DCAMERA, cam->is);
	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || (!ft_isdigit(*s) && *s != '-'));
	IF_F(',' != *(s += ft_digits(X(cam->pos) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(Y(cam->pos) = ft_atoi(s))) || !*s++);
	IF_F(' ' != *(s += ft_digits(Z(cam->pos) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(X(cam->dir) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(Y(cam->dir) = ft_atoi(s))) || !*s++);
	IF_F(*(s += ft_digits(Z(cam->dir) = -ft_atoi(s))));
	if (Y(cam->pos) != 0.0f)
		Y(cam->pos) = -Y(cam->pos);
	cam->is = true;
	return (true);
}

inline bool	rt_slight(Light *l, string s)
{
	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || (!ft_isdigit(*s) && *s != '-'));
	IF_F(',' != *(s += ft_digits(X(l->pos) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(Y(l->pos) = ft_atoi(s))) || !*s++);
	IF_F(' ' != *(s += ft_digits(Z(l->pos) = ft_atoi(s))) || !*s++);
	IF_F(*(s += ft_digits(l->intens = ft_atoi(s))));
	if (Y(l->pos) != 0.0f)
		Y(l->pos) = -Y(l->pos);
	IFDO(0 < l->intens, l->intens /= 100);
	return (true);
}
