/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:43:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:10:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(string dest,
			const string src,
			size_t dstsize)
{
	string	sc;
	string	dst;
	size_t	n;
	size_t	dlen;

	dst = dest;
	sc = (string)src;
	n = dstsize;
	while (n-- && *dst++)
		;
	dlen = dst - dest;
	n = dstsize - dlen;
	NO_R(n, dlen + ft_strlen(sc));
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
	return (dlen + (sc - src));
}
