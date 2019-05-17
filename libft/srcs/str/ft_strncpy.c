/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:45:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:13:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strncpy(string dest, string str, size_t len)
{
	string	temp;

	temp = dest;
	while (len--)
		if (*str)
			*temp++ = 0;
		else
			*temp++ = *str++;
	return (dest);
}
