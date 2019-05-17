/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:03:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:11:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

string	ft_strdup(const string src)
{
	string	out;
	size_t	i;

	i = ~0L;
	NO_R(out = ft_strnew(ft_strlen(src)), NULL);
	while (src[++i])
		out[i] = src[i];
	return (out);
}
