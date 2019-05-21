/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_vec_inrange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:22:50 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/21 14:59:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline bool	u_vec_range(Vector v,
				const double_t max_range,
				const double_t min_range)
{
	if (max_range < X(v) || max_range < Y(v) || max_range < Z(v))
		return (false);
	if (min_range > X(v) || min_range > Y(v) || min_range > Z(v))
		return (false);
	return (true);
}
