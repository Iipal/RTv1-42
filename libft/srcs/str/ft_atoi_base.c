/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:46:01 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/15 18:03:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline bool	add_isvalid(const uchar c, int8_t base,
								cstring vl, cstring vu)
{
	while (base--)
		if (vl[base] == c || vu[base] == c)
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

inline int32_t		ft_atoi_base(cstring str, int8_t base)
{
	int32_t	num;
	int8_t	sign;
	string	valid_lower;
	string	valid_upper;

	num = 0;
	valid_lower = ft_strdup("0123456789abcdef");
	valid_upper = ft_strdup("0123456789ABCDEF");
	str += ft_skip_blanks(str);
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (add_isvalid(*str, base, valid_lower, valid_upper))
		num = num * base + add_value_of(*str++);
	ft_strdel(&valid_lower);
	ft_strdel(&valid_upper);
	return (num * sign);
}
