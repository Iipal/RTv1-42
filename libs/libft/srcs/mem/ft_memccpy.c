/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:43:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 09:36:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dest,
			const void *restrict src,
			uint8_t c,
			size_t n)
{
	uint8_t			*dst;
	const uint8_t	*sc = (const uint8_t*)src;
	size_t			i;

	dst = (uint8_t*)dest;
	i = ~0UL;
	while (n > ++i)
	{
		dst[i] = sc[i];
		if (sc[i] == c)
			return (dst + i + 1);
	}
	return (NULL);
}
