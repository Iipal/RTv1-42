/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_vdivv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:11:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 14:11:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vectors.h"

inline const Vector	u_vdivv(const Vector a, const Vector b)
{
	const Vector	c = {X(a) / X(b), Y(a) / Y(b), Z(a) / Z(b), 0.0};

	return (c);
}
