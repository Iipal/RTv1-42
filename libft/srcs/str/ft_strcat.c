/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:35:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:14:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strcat(string dest, const string src)
{
	const size_t	i = ft_strlen(dest);
	size_t			j;

	j = ~0L;
	while (src[++j])
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
