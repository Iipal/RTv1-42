/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdigits_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:41:00 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 09:49:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_fdigits_str(const char *restrict str)
{
	const int64_t	exp = ft_atol(str);
	int64_t			mantissa;
	size_t			mantissa_digits;
	bool			sign;
	size_t			i;

	i = ~0UL;
	mantissa = 0;
	mantissa_digits = 0;
	sign = ('-' == *str) ? true : false;
	(!exp && sign) ? ++str : str;
	str += ft_digits(exp);
	if ('.' == *(str++))
	{
		while (str[++i] && F_ISDIGIT(str[i]))
			++mantissa_digits;
		mantissa = ft_atol(str);
		if (mantissa_digits <= ft_digits(mantissa))
			mantissa_digits = 0;
		else
			mantissa_digits -= ft_digits(mantissa);
		return (ft_digits(exp) + ft_digits(mantissa) + mantissa_digits
			+ 1 + ((!exp && sign) ? 1 : 0));
	}
	return (ft_digits(exp) + ((!exp && sign) ? 1 : 0));
}
