/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:19:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:16:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strstr(string str, string to_find)
{
	string cp;
	string s1;
	string s2;

	cp = (string)str;
	NO_R(*to_find, (string)str);
	while (*cp)
	{
		s1 = cp;
		s2 = (string)to_find;
		while (*s1 && *s2 && !(*s1 - *s2))
		{
			s1++;
			s2++;
		}
		NO_R(*s2, cp);
		cp++;
	}
	return (NULL);
}
