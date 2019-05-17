/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:11:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:28:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline string	ft_strjoin(char const *s1, char const *s2)
{
	string	out;
	size_t	len1;
	size_t	len2;

	out = NULL;
	IFR(!s1 || !s2, out);
	len1 = ft_strlen((const string)s1);
	len2 = ft_strlen((const string)s2);
	NO_R(out = ft_strnew((len1 ? len1 : 1) + (len2 ? len2 : 1)), out);
	out = ft_strcpy(out, (const string)s1);
	out = ft_strcpy(out + len1, (const string)s2);
	return (out - len1);
}
