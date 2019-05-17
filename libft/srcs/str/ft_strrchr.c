/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:07:43 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:16:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline string	ft_strrchr(string s, const uchar c)
{
	int32_t	len;

	len = ft_strlen((string)s);
	while (len > 0 && s[len] != c)
		--len;
	if (s[len] == c)
		return ((string)&s[len]);
	return (NULL);
}
