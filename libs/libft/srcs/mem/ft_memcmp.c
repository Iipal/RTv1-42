/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:13:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 09:33:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_memcmp(const void *restrict s1, const void *restrict s2, size_t n)
{
	const uint8_t	*str1 = (const uint8_t*)s1;
	const uint8_t	*str2 = (const uint8_t*)s2;

	if (str1 == str2 || !n)
		return (0);
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (n)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
