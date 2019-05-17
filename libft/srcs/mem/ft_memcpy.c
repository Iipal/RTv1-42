/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:04:50 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:23:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

pvoid	ft_memcpy(pvoid dest, const pvoid src, const size_t n)
{
	size_t	i;
	string	dst;
	string	sc;

	i = ~0L;
	sc = (string)src;
	dst = (string)dest;
	while (++i < n)
		dst[i] = sc[i];
	return (dest);
}
