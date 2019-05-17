/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:46:01 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:09:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline bool	add_isvalid(const uchar c, int8_t base, const string valid)
{
	while (base--)
		if (valid[base] == ft_tolower(c))
			return (true);
	return (false);
}

static inline uchar	add_value_of(uint8_t c)
{
	IFR(ft_isdigit(c), c - '0');
	IFR(ft_islower(c), c - 'a' + 10);
	IFR(ft_isupper(c), c - 'A' + 10);
	return (0);
}

int32_t				ft_atoi_base(string str, int8_t base)
{
	int32_t			num;
	int8_t			sign;
	const string	valid_hex = "0123456789abcdef";

	num = 0;
	str += ft_skip_blanks(str);
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (add_isvalid(*str, base, valid_hex))
		num = num * base + add_value_of(*str++);
	return (num * sign);
}
