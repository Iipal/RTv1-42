/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_inrange.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:22:50 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/18 17:02:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline bool	ft_vec_inrange(const Vector v,
					const double_t max_range,
					const double_t min_range)
{
	if (max_range < X(v) || min_range > X(v))
		return (false);
	if (max_range < Y(v) || min_range > Y(v))
		return (false);
	if (max_range < Z(v) || min_range > Z(v))
		return (false);
	return (true);
}
