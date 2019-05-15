/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:20:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/15 18:31:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline size_t	ft_strlcpy(string dest, cstring str, size_t dstsize)
{
	size_t	strsize;

	NO_F(str);
	strsize = ft_strlen(str);
	if (strsize < dstsize)
		ft_memcpy(dest, (pvoid)str, strsize + 1);
	else if (dstsize)
	{
		ft_memcpy(dest, (pvoid)str, dstsize - 1);
		dest[dstsize - 1] = '\0';
	}
	return (strsize);
}
