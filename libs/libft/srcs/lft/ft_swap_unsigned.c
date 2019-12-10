/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 01:07:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 13:33:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void __attribute__((__overloadable__))
	ft_swap(unsigned char *restrict a, unsigned char *restrict b)
{
	unsigned char	c;

	c = *a;
	*a = *b;
	*b = c;
}

inline void __attribute__((__overloadable__))
	ft_swap(unsigned short *restrict a, unsigned short *restrict b)
{
	unsigned short	c;

	c = *a;
	*a = *b;
	*b = c;
}

inline void __attribute__((__overloadable__))
	ft_swap(unsigned int *restrict a, unsigned int *restrict b)
{
	unsigned int	c;

	c = *a;
	*a = *b;
	*b = c;
}

inline void __attribute__((__overloadable__))
	ft_swap(unsigned long *restrict a, unsigned long *restrict b)
{
	unsigned long	c;

	c = *a;
	*a = *b;
	*b = c;
}
