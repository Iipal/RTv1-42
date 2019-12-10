/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:04:50 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/12 17:33:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest,
			const void *restrict src,
			size_t n)
{
	char		*dst;
	const char	*sc = (const char*)src;
	size_t		i;

	i = ~0UL;
	dst = (char*)dest;
	while (n > ++i)
		dst[i] = sc[i];
	return (dest);
}
