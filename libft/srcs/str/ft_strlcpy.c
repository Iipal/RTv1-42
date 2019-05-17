/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:20:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:10:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(string dest, const string str, const size_t dstsize)
{
	const size_t	strsize = ft_strlen(str);

	NO_F(str);
	if (strsize < dstsize)
		ft_memcpy(dest, (pvoid)str, strsize + 1);
	else if (dstsize)
	{
		ft_memcpy(dest, (pvoid)str, dstsize - 1);
		dest[dstsize - 1] = '\0';
	}
	return (strsize);
}
