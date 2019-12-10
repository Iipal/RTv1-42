/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 10:33:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/18 00:47:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(int64_t n)
{
	char	*out;
	size_t	len;
	bool	sign;

	sign = 0L > n ? true : false;
	len = ft_digits(n);
	if (!(out = ft_strnew(len)))
		return (out);
	while (len--)
	{
		out[len] = (sign ? -(n % 0xAL) : n % 0xAL) + 0x30L;
		n /= 0xAL;
	}
	*out = sign ? '-' : *out;
	return (out);
}
