/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:17:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:25:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

pvoid	ft_memset(pvoid dest, const int32_t c, size_t len)
{
	ustring	out;

	out = (ustring)dest;
	while (len--)
		*out++ = c;
	return (dest);
}
