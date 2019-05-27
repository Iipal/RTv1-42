/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_vsubv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:10:46 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 14:11:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vectors.h"

inline const Vector	u_vsubv(const Vector a, const Vector b)
{
	const Vector	c = {X(a) - X(b), Y(a) - Y(b), Z(a) - Z(b), 0.0};

	return (c);
}
