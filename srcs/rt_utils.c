/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:44:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/09 11:55:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool		u_inrange(t_vec v, bool check_min, bool check_max)
{
	if (check_max
	&& (MAX_X < v[X] || MAX_Y < v[Y] || MAX_Z < v[Z]))
		return (false);
	if (check_min
	&& (MIN_X > v[X] || MIN_Y > v[Y] || MIN_Z > v[Z]))
		return (false);
	return (true);
}

inline double_t	u_inrangev(double_t v, bool check_min, bool check_max)
{
	if (check_max && MAX_X < v)
		return (MAX_X);
	if (check_min && MIN_X > v)
		return (MIN_X);
	return (v);
}
