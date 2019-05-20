/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:23:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/20 12:15:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_ishex_str(string str)
{
	size_t			j;
	const string	valid_hex = "0123456789abcdef";

	while (*str && (j = ~0L))
	{
		while (valid_hex[++j])
			if (ft_tolower(*str) == valid_hex[j])
				break ;
		if (ft_tolower(*str++) != valid_hex[j])
			return (false);
	}
	return (true);
}
