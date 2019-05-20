/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex_strn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 12:40:50 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/20 12:16:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_ishex_strn(string str, size_t n)
{
	size_t			j;
	const string	valid_hex = "0123456789abcdef";

	while (n-- && (j = ~0L))
	{
		while (valid_hex[++j])
			if (ft_tolower(*str) == valid_hex[j])
				break ;
		if (ft_tolower(*str++) != valid_hex[j])
			return (false);
	}
	return (true);
}
