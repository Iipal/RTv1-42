/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_isd_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 21:34:16 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/18 22:37:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline bool	u_isd_range(double_t x,
				const double_t max_range,
				const double_t min_range)
{
	if (max_range < x || min_range > x)
		return (false);
	return (true);
}
