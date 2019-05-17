/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:43:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:24:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

pvoid	ft_memccpy(pvoid dest,
					const pvoid src,
					uint8_t c, size_t n)
{
	ustring	dst;
	ustring	sc;
	size_t	i;

	dst = (ustring)dest;
	sc = (ustring)src;
	i = ~0L;
	while (++i < n)
	{
		dst[i] = sc[i];
		if (sc[i] == c)
			return (dst + i + 1);
	}
	return (NULL);
}
