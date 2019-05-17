/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:43:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:24:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

pvoid	ft_memmove(pvoid dest, void const *src, size_t len)
{
	size_t	i;
	ustring	dst;
	ustring	sc;

	i = ~0L;
	sc = (ustring)src;
	dst = (ustring)dest;
	if (sc < dst)
		while (--len)
			dst[len] = sc[len];
	else
		while (++i < len)
			dst[i] = sc[i];
	return (dest);
}
