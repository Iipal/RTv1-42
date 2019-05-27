/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_vsubd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:04:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 14:04:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vectors.h"

inline const Vector	u_vsubd(const Vector v, const double_t d)
{
	const Vector	out = {X(v) - d, Y(v) - d, Z(v) - d, 0.0};

	return (out);
}
