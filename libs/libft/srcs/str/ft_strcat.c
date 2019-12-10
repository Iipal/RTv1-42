/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:35:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 11:32:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict dest, const char *restrict src)
{
	const size_t	dest_len = ft_strlen(dest);
	size_t			i;

	i = ~0UL;
	while (src[++i])
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}
