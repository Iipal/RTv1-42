/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:44:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/12 21:48:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool		u_inrange(const t_v v,
	const bool check_min, const bool check_max)
{
	if (check_max
	&& (MAX_X < X(v) || MAX_Y < Y(v) || MAX_Z < Z(v)))
		return (false);
	if (check_min
	&& (MIN_X > X(v) || MIN_Y > Y(v) || MIN_Z > Z(v)))
		return (false);
	return (true);
}

inline double_t	u_inrangev(const double_t v,
	const bool check_min, const bool check_max)
{
	if (check_max && MAX_X < v)
		return (MAX_X);
	if (check_min && MIN_X > v)
		return (MIN_X);
	return (v);
}
