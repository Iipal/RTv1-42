/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:26:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:30:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline string	ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;

	NO_R(s, NULL);
	start = ft_skip_blanks((const string)s);
	NO_R(s[start], ft_strdup((const string)(s + start)));
	len = ft_strlen((const string)s) - 1;
	while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && len > 0)
		--len;
	return (ft_strsub(s, start, len - start + 1));
}
