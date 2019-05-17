/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:41:32 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:18:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strnstr(string str, string to_find, size_t len)
{
	const size_t	n = ft_strlen(to_find);

	NO_R(*to_find, (string)str);
	while (*str && len-- >= n)
	{
		if (*str && *to_find
		&& !ft_memcmp((pvoid)str, (pvoid)to_find, n))
			return ((string)str);
		++str;
	}
	return (NULL);
}
