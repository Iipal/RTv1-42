/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 00:13:20 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 13:34:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa(unsigned long num, char *restrict dst, int base)
{
	char	temp[17];
	long	digit;
	long	i;
	long	j;
	bool	dowhile_reduce;

	j = 0L;
	i = 0L;
	dowhile_reduce = true;
	while (num > 0 || dowhile_reduce)
	{
		dowhile_reduce = false;
		digit = num % base;
		if (digit < 10L)
			temp[i++] = digit + '0';
		else
			temp[i++] = digit - 10 + 'A';
		num /= (unsigned long)base;
	}
	--i;
	while (i >= 0L)
		dst[j++] = temp[i--];
	dst[j] = 0;
	return (dst);
}
