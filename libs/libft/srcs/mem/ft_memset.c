/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:17:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/18 00:30:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *restrict dest, int32_t c, size_t len)
{
	uint8_t	*out;

	out = (uint8_t*)dest;
	while (len--)
		*out++ = (uint8_t)c;
	return (dest);
}
