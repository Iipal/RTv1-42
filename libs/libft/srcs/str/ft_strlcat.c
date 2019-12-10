/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:43:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/18 00:43:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dest,
			const char *restrict src,
			size_t dstsize)
{
	const char	*sc = (const char*)src;
	char		*dst;
	size_t		dlen;
	size_t		n;

	dst = dest;
	n = dstsize;
	while (n-- && *dst++)
		;
	dlen = (size_t)(dst - dest);
	if (!(n = dstsize - dlen))
		return (dlen + ft_strlen(sc));
	while (*sc != '\0')
	{
		if (n != 1)
		{
			*dst++ = *sc;
			n--;
		}
		++sc;
	}
	*dst = '\0';
	return (dlen + (size_t)(sc - src));
}
