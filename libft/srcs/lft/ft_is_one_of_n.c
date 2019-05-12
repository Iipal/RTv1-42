/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_one_of_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 08:33:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/12 14:33:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_one_of_n(int64_t cmp, size_t n, ...)
{
	va_list	ap;
	bool	is_one_of;

	va_start(ap, n);
	is_one_of = false;
	while (n--)
		if (cmp == va_arg(ap, int64_t))
			is_one_of = true;
	va_end(ap);
	return (is_one_of);
}
