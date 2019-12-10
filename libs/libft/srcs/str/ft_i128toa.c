/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i128toa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 00:22:59 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/22 13:35:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_i128toa(__int128 n)
{
	char		*out;
	__int128_t	len;
	bool		sign;

	len = (__int128_t)ft_digits((int64_t)n);
	sign = 0 > n ? true : false;
	if (!(out = ft_strnew((size_t)(len + sign))))
		return (out);
	while (len--)
	{
		out[len] = (sign ? -(n % 0xA) : n % 0xA) + 0x30;
		n /= 0xA;
	}
	*out = sign ? '-' : *out;
	return (out);
}
