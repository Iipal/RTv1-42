/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_vaddd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:02:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 16:06:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vectors.h"

inline Vector	u_vaddd(const Vector v, const double_t d)
{
	const Vector	out = {X(v) + d, Y(v) + d, Z(v) + d, 0.0};

	return (out);
}
