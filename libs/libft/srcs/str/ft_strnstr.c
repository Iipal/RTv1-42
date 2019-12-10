/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:41:32 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 12:00:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, const char *restrict to_find, size_t len)
{
	const size_t	to_find_len = ft_strlen(to_find);

	if (!*to_find)
		return (str);
	while (*str && len-- >= to_find_len)
	{
		if (*str && !ft_strncmp(str, to_find, to_find_len))
			return (str);
		++str;
	}
	return (NULL);
}
