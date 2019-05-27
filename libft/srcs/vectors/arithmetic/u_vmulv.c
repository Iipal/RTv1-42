/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_vmulv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:11:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 14:12:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vectors.h"

inline const Vector	u_vmulv(const Vector a, const Vector b)
{
	const Vector	c = {X(a) * X(b), Y(a) * Y(b), Z(a) * Z(b), 0.0};

	return (c);
}
