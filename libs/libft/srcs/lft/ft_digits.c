/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:45:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 00:43:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_digits(int64_t n)
{
	size_t	out;

	out = 1;
	if (0 > n && ++out)
		n = -n;
	while (n /= 10)
		++out;
	return (out);
}
