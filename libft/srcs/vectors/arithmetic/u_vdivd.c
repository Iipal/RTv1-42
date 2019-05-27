/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_vdivd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:04:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 16:07:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vectors.h"

inline Vector	u_vdivd(const Vector v, const double_t d)
{
	const Vector	out = {X(v) / d, Y(v) / d, Z(v) / d, 0.0};

	return (out);
}
