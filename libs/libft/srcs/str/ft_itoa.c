/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 10:33:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 13:34:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int32_t n)
{
	char	*out;
	size_t	len;
	bool	sign;

	len = ft_digits(n);
	sign = (0 > n) ? true : false;
	if (!(out = ft_strnew(len)))
		return (out);
	while (len--)
	{
		out[len] = (sign ? -(n % 0xA) : n % 0xA) + 0x30;
		n /= 0xA;
	}
	*out = sign ? '-' : *out;
	return (out);
}
