/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:31:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/10 19:53:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_ssphere(Object *restrict const obj, string s)
{
	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || ('-' != *s && !ft_isdigit(*s)));
	NO_F(rt_read_vec(&s, &obj->pos));
	NO_F(rt_read_vec(&s, &obj->dir));
	IF_F(*s++ != '0' || *s++ != 'x');
	NO_F(ft_ishex_strn(s, ft_skip_to_blank(s)));
	NO_F(obj->clr.hex = ft_atoi_base(s, 16));
	IF_F(' ' != *(s += ft_skip_to_blank(s)) || !*s++);
	obj->radius = ft_atof(s);
	IF_F(' ' != *(s += ft_fdigits_str(s)) || !*s++);
	IF_F(*(s += ft_digits(obj->spec = ft_atoi(s))));
	if (Y(obj->pos) != 0.0f)
		Y(obj->pos) = -Y(obj->pos);
	obj->fn_normal_calc = rt_normal_sphere;
	obj->fn_inter_calc = rt_inter_sphere;
	obj->fn_uv = rt_uv_sphere;
	obj->type = sphere;
	return (true);
}

inline bool	rt_scone(Object *restrict const obj, string s)
{
	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || ('-' != *s && !ft_isdigit(*s)));
	NO_F(rt_read_vec(&s, &obj->pos));
	NO_F(rt_read_vec(&s, &obj->dir));
	IF_F(*s++ != '0' || *s++ != 'x');
	NO_F(ft_ishex_strn(s, ft_skip_to_blank(s)));
	NO_F(obj->clr.hex = ft_atoi_base(s, 16));
	IF_F(' ' != *(s += ft_skip_to_blank(s)) || !*s++);
	obj->radius = ft_atof(s);
	IF_F(' ' != *(s += ft_fdigits_str(s)) || !*s++);
	IF_F(*(s += ft_digits(obj->spec = ft_atoi(s))));
	if (Y(obj->pos) != 0.0f)
		Y(obj->pos) = -Y(obj->pos);
	obj->fn_normal_calc = rt_normal_cone;
	obj->fn_inter_calc = rt_inter_cone;
	obj->fn_uv = rt_uv_cone;
	obj->type = cone;
	return (true);
}

inline bool	rt_splane(Object *restrict const obj, string s)
{
	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || ('-' != *s && !ft_isdigit(*s)));
	NO_F(rt_read_vec(&s, &obj->pos));
	NO_F(rt_read_vec(&s, &obj->dir));
	IF_F(*s++ != '0' || *s++ != 'x');
	NO_F(ft_ishex_strn(s, ft_skip_to_blank(s)));
	NO_F(obj->clr.hex = ft_atoi_base(s, 16));
	IF_F(' ' != *(s += ft_skip_to_blank(s)) || !*s++);
	IF_F(*(s += ft_digits(obj->spec = ft_atoi(s))));
	if (Y(obj->pos) != 0.0f)
		Y(obj->pos) = -Y(obj->pos);
	obj->fn_normal_calc = rt_normal_plane;
	obj->fn_inter_calc = rt_inter_plane;
	obj->fn_uv = rt_uv_plane;
	obj->type = plane;
	return (true);
}

inline bool	rt_scylinder(Object *restrict const obj, string s)
{
	s += ft_skip_to_blank(s);
	IF_F(*s++ != ' ');
	IF_F(!*s || ('-' != *s && !ft_isdigit(*s)));
	NO_F(rt_read_vec(&s, &obj->pos));
	NO_F(rt_read_vec(&s, &obj->dir));
	IF_F(*s++ != '0' || *s++ != 'x');
	NO_F(ft_ishex_strn(s, ft_skip_to_blank(s)));
	NO_F(obj->clr.hex = ft_atoi_base(s, 16));
	IF_F(' ' != *(s += ft_skip_to_blank(s)) || !*s++);
	obj->radius = ft_atof(s);
	IF_F(' ' != *(s += ft_fdigits_str(s)) || !*s++);
	IF_F(*(s += ft_digits(obj->spec = ft_atoi(s))));
	if (Y(obj->pos) != 0.0f)
		Y(obj->pos) = -Y(obj->pos);
	obj->fn_normal_calc = rt_normal_cylinder;
	obj->fn_inter_calc = rt_inter_cylinder;
	obj->fn_uv = rt_uv_cylinder;
	obj->type = cylinder;
	return (true);
}
