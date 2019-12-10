/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:03:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 11:31:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *restrict dest, const char *restrict str)
{
	size_t	i;

	i = ~0UL;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}
