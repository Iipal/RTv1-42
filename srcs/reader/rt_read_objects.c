/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:31:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/15 10:48:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_ssphere(Object *obj, string s)
{
	Uint32	clr;

	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || ('-' != *s && !ft_isdigit(*s)));
	IF_F(',' != *(s += ft_digits(X(obj->pos) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(Y(obj->pos) = ft_atoi(s))) || !*s++);
	IF_F(' ' != *(s += ft_digits(Z(obj->pos) = ft_atoi(s))) || !*s++);
	IF_F(*s++ != '0' || *s++ != 'x');
	NO_F(clr = ft_atoi_base(s, 16));
	IF_F(' ' != *(s += ft_skip_to_blank(s)) || !*s++);
	IF_F(' ' != *(s += ft_digits(obj->radius = ft_atoi(s))) || !*s++);
	IF_F(*(s += ft_digits(obj->spec = ft_atoi(s))));
	if (Y(obj->pos) != 0.0f)
		Y(obj->pos) = -Y(obj->pos);
	obj->clr = (Color){clr >> 16, (clr >> 8) & 0xff, clr & 0xff};
	obj->type = sphere;
	return (true);
}

inline bool	rt_splane(Object *obj, string s)
{
	Uint32	clr;

	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || ('-' != *s && !ft_isdigit(*s)));
	IF_F(',' != *(s += ft_digits(X(obj->pos) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(Y(obj->pos) = ft_atoi(s))) || !*s++);
	IF_F(' ' != *(s += ft_digits(Z(obj->pos) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(X(obj->dir) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(Y(obj->dir) = ft_atoi(s))) || !*s++);
	IF_F(' ' != *(s += ft_digits(Z(obj->dir) = ft_atoi(s))) || !*s++);
	IF_F(*s++ != '0' || *s++ != 'x');
	NO_F(clr = ft_atoi_base(s, 16));
	IF_F(' ' != *(s += ft_skip_to_blank(s)) || !*s++);
	IF_F(*(s += ft_digits(obj->spec = ft_atoi(s))));
	if (Y(obj->pos) != 0.0f)
		Y(obj->pos) = -Y(obj->pos);
	obj->clr = (Color){clr >> 16, (clr >> 8) & 0xff, clr & 0xff};
	obj->type = plane;
	return (true);
}

inline bool	rt_scylinder(Object *obj, string s)
{
	Uint32	clr;

	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || ('-' != *s && !ft_isdigit(*s)));
	IF_F(',' != *(s += ft_digits(X(obj->pos) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(Y(obj->pos) = ft_atoi(s))) || !*s++);
	IF_F(' ' != *(s += ft_digits(Z(obj->pos) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(X(obj->dir) = ft_atoi(s))) || !*s++);
	IF_F(',' != *(s += ft_digits(Y(obj->dir) = ft_atoi(s))) || !*s++);
	IF_F(' ' != *(s += ft_digits(Z(obj->dir) = ft_atoi(s))) || !*s++);
	IF_F(*s++ != '0' || *s++ != 'x');
	NO_F(clr = ft_atoi_base(s, 16));
	IF_F(' ' != *(s += ft_skip_to_blank(s)) || !*s++);
	IF_F(' ' != *(s += ft_digits(obj->radius = ft_atoi(s))) || !*s++);
	IF_F(*(s += ft_digits(obj->spec = ft_atoi(s))));
	if (Y(obj->pos) != 0.0f)
		Y(obj->pos) = -Y(obj->pos);
	obj->clr = (Color){clr >> 16, (clr >> 8) & 0xff, clr & 0xff};
	obj->type = cylinder;
	return (true);
}
