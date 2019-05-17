/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:41:43 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:10:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uchar	ft_strncmp(string s1, string s2, size_t n)
{
	uchar	u1;
	uchar	u2;

	while (n-- > 0)
	{
		u1 = (uchar)*s1++;
		u2 = (uchar)*s2++;
		if (u1 != u2)
			return (u1 - u2);
		if (!u1)
			return (0);
	}
	return (0);
}
