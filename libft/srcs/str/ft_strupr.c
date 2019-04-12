/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:08:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 13:27:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strupr(string str)
{
	string	s;

	s = str;
	while (*s)
	{
		*s = ft_toupper((uint8_t)(*s));
		++s;
	}
	return (str);
}
