/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_vnorm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 22:34:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/22 10:21:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline Vector	u_vnorm(const Vector v)
{
	const double_t	sqrt_vdv = sqrt(u_vdot(v, v));

	return ((Vector){X(v) / sqrt_vdv, Y(v) / sqrt_vdv, Z(v) / sqrt_vdv});
}
