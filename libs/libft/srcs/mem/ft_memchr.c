/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:04:22 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/18 15:26:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *restrict ptr, int c, size_t n)
{
	const char	*out = (const char*)ptr;
	size_t		i;

	i = ~0UL;
	while (n--)
		if (out[++i] == c)
			return ((void*)(out + i));
	return (NULL);
}
