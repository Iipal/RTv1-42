/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_one_of_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 23:08:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/13 20:05:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_one_of_str(cstring cmp, size_t n, bool cmp_len, ...)
{
	va_list	ap;
	bool	is_one_of;
	char	*temp;

	is_one_of = false;
	va_start(ap, cmp_len);
	while (n--)
	{
		temp = va_arg(ap, char*);
		if (true == cmp_len && !ft_strncmp(cmp, temp, ft_strlen(temp)))
		{
			is_one_of = true;
			break ;
		}
		else if (false == cmp_len && !ft_strcmp(cmp, temp))
		{
			is_one_of = true;
			break ;
		}
	}
	va_end(ap);
	return (is_one_of);
}
