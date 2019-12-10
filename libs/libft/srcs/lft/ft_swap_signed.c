/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 00:55:06 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 13:34:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void __attribute__((__overloadable__))
	ft_swap(char *restrict a, char *restrict b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

inline void __attribute__((__overloadable__))
	ft_swap(short *restrict a, short *restrict b)
{
	short	c;

	c = *a;
	*a = *b;
	*b = c;
}

inline void __attribute__((__overloadable__))
	ft_swap(int *restrict a, int *restrict b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

inline void __attribute__((__overloadable__))
	ft_swap(long *restrict a, long *restrict b)
{
	long	c;

	c = *a;
	*a = *b;
	*b = c;
}
