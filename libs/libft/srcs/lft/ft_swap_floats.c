/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_floats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:35:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 17:36:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void __attribute__((__overloadable__))
ft_swap(float *restrict a, float *restrict b)
{
	float	c;

	c = *a;
	*a = *b;
	*b = c;
}

inline void __attribute__((__overloadable__))
ft_swap(double *restrict a, double *restrict b)
{
	double	c;

	c = *a;
	*a = *b;
	*b = c;
}
