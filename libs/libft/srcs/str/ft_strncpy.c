/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:45:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/26 11:39:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *restrict dest,
			const char *restrict str,
			size_t len)
{
	const size_t	size = ft_strnlen(str, len);

	if (size != len)
		ft_memset(dest + size, '\0', len - size);
	return (ft_memcpy(dest, str, size));
}
