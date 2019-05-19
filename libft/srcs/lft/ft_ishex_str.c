/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:23:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/19 12:53:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_ishex_str(const string str)
{
	size_t			i;
	size_t			j;
	const string	valid_hex = "0123456789abcdef";
	bool			is_valid;

	i = ~0L;
	while (str[++i] && (j = ~0L))
	{
		is_valid = false;
		while (valid_hex[++j])
			if (ft_tolower(str[i]) == valid_hex[j])
				is_valid = true;
		if (false == is_valid)
			return (false);
	}
	return (true);
}
