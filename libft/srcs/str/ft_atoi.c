/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:11:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:08:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_atoi(string str)
{
	int32_t	num;
	int8_t	sign;

	sign = 0;
	num = 0;
	str += ft_skip_blanks(str);
	sign = (*str == '-') ? -1 : 1;
	IFDO(*str == '-' || *str == '+', ++str);
	while (ft_isdigit(*str))
		num = num * 10 + *(str++) - 48;
	return (num * sign);
}
