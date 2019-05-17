/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:23:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 12:54:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_ishex_str(const string str)
{
	size_t			i;
	size_t			j;
	const string	valid_hex = "0123456789abcdef";

	i = ~0L;
	while (str[++i] && (j = 16))
		while (valid_hex[--j])
			if (ft_tolower(str[i]) != valid_hex[j])
				return (false);
	return (true);
}
