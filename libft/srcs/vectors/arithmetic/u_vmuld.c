/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_vmuld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:29:43 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 14:03:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vectors.h"

inline const Vector	u_vmuld(const Vector v, const double_t d)
{
	const Vector	out = {X(v) * d, Y(v) * d, Z(v) * d, 0.0};

	return (out);
}
