/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:31:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/20 19:51:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_ssphere(Object *const obj, string s)
{
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
	NO_F(ft_ishex_strn(s, ft_skip_to_blank(s)));
	NO_F(obj->clr.hex = ft_atoi_base(s, 16));
	IF_F(' ' != *(s += ft_skip_to_blank(s)) || !*s++);
	IF_F(' ' != *(s += ft_digits(obj->radius = ft_atoi(s))) || !*s++);
	IF_F(*(s += ft_digits(obj->spec = ft_atoi(s))));
	if (Y(obj->pos) != 0.0f)
		Y(obj->pos) = -Y(obj->pos);
	obj->fn_normal_calc = rt_normal_sphere;
	obj->fn_inter_calc = rt_inter_sphere;
	obj->type = sphere;
	return (true);
}

inline bool	rt_scone(Object *const obj, string s)
{
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
	NO_F(ft_ishex_strn(s, ft_skip_to_blank(s)));
	NO_F(obj->clr.hex = ft_atoi_base(s, 16));
	IF_F(' ' != *(s += ft_skip_to_blank(s)) || !*s++);
	IF_F(' ' != *(s += ft_digits(obj->radius = ft_atoi(s))) || !*s++);
	IF_F(*(s += ft_digits(obj->spec = ft_atoi(s))));
	if (Y(obj->pos) != 0.0f)
		Y(obj->pos) = -Y(obj->pos);
	obj->fn_normal_calc = rt_normal_cone;
	obj->fn_inter_calc = rt_inter_cone;
	obj->type = cone;
	return (true);
}

inline bool	rt_splane(Object *const obj, string s)
{
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
	NO_F(ft_ishex_strn(s, ft_skip_to_blank(s)));
	NO_F(obj->clr.hex = ft_atoi_base(s, 16));
	IF_F(' ' != *(s += ft_skip_to_blank(s)) || !*s++);
	IF_F(*(s += ft_digits(obj->spec = ft_atoi(s))));
	if (Y(obj->pos) != 0.0f)
		Y(obj->pos) = -Y(obj->pos);
	obj->fn_normal_calc = rt_normal_plane;
	obj->fn_inter_calc = rt_inter_plane;
	obj->type = plane;
	return (true);
}

inline bool	rt_scylinder(Object *const obj, string s)
{
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
	NO_F(ft_ishex_strn(s, ft_skip_to_blank(s)));
	NO_F(obj->clr.hex = ft_atoi_base(s, 16));
	IF_F(' ' != *(s += ft_skip_to_blank(s)) || !*s++);
	IF_F(' ' != *(s += ft_digits(obj->radius = ft_atoi(s))) || !*s++);
	IF_F(*(s += ft_digits(obj->spec = ft_atoi(s))));
	if (Y(obj->pos) != 0.0f)
		Y(obj->pos) = -Y(obj->pos);
	obj->fn_normal_calc = rt_normal_cylinder;
	obj->fn_inter_calc = rt_inter_cylinder;
	obj->type = cylinder;
	return (true);
}
