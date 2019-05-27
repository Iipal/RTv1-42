/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_vnorm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 22:34:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 14:18:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline Vector	u_vnorm(const Vector v)
{
	const double_t	sqrtvdv = sqrt(u_vdot(v, v));
	const Vector	c = {X(v) / sqrtvdv, Y(v) / sqrtvdv, Z(v) / sqrtvdv, 0.0};

	return (c);
}
