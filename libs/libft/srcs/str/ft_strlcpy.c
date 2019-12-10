/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:20:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 11:27:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline size_t	ft_strlcpy(char *restrict dest,
					const char *restrict str,
					size_t dstsize)
{
	size_t const	strsize = ft_strlen(str);

	if (strsize < dstsize)
		ft_strncpy(dest, str, strsize + 1);
	else if (dstsize)
	{
		ft_strncpy(dest, str, dstsize - 1);
		dest[dstsize - 1] = '\0';
	}
	return (strsize);
}
