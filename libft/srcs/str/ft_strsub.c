/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:07:51 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:20:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strsub(char const *s, const size_t start, const size_t len)
{
	string	src;
	string	out;
	size_t	i;
	size_t	j;

	out = NULL;
	NO_R(s, NULL);
	NO_R(out = ft_strnew(len ? len : 1), NULL);
	if (!len)
	{
		out[0] = '\0';
		return (out);
	}
	src = (string)s;
	i = start;
	j = ~0L;
	while (++j < len)
		out[j] = src[i++];
	return (out);
}
