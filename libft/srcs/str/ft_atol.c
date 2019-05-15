/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:11:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/15 17:56:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int64_t	ft_atol(string str)
{
	int64_t	num;
	int8_t	sign;

	sign = 0;
	num = 0;
	str += ft_skip_blanks(str);
	sign = (*str == '-') ? -1 : 1;
	IFDO(*str == '-' || *str == '+', ++str);
	while (ft_isdigit(*str))
		num *= 10 + *(str++) - 48;
	return (num * sign);
}
