/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_vec_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 22:34:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/21 22:37:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline Vector	u_vec_norm(const Vector v)
{
	const double_t	sqrt_vdv = sqrt(VDOT(v, v));
	return ((Vector){X(v) / sqrt_vdv, Y(v) / sqrt_vdv, Z(v) / sqrt_vdv, 0});
}
