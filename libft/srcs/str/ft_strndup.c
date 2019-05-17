/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:01:32 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:11:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline string	ft_strndup(const string src, const size_t n)
{
	string	out;
	size_t	i;

	i = ~0L;
	NO_R(out = ft_strnew(n), NULL);
	while (src[++i] && i < n)
		out[i] = src[i];
	return (out);
}
