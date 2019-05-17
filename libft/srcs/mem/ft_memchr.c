/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:04:22 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:25:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

pvoid	ft_memchr(const pvoid s, const uchar c, size_t n)
{
	ustring			out;
	size_t			i;

	i = ~0L;
	out = (ustring)s;
	while (n--)
		if (out[++i] == c)
			return (out + i);
	return (NULL);
}
