/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_read_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:47:11 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/10 19:47:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_read_vec(string *const s, __v4df *const v)
{
	string	str;
	__v4df	vec;

	vec = *v;
	str = *s;
	X(vec) = ft_atof(str);
	IF_F(',' != *(str += ft_fdigits_str(str)) || !*str++);
	Y(vec) = ft_atof(str);
	IF_F(',' != *(str += ft_fdigits_str(str)) || !*str++);
	Z(vec) = ft_atof(str);
	IF_F(' ' != *(str += ft_fdigits_str(str)) || !*str++);
	*v = vec;
	*s = str;
	return (true);
}
