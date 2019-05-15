/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:03:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/15 18:38:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline string	ft_strcpy(string dest, cstring str)
{
	size_t	i;

	i = ~0L;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}
