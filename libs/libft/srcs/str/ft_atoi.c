/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:11:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 11:48:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_atoi(const char *str)
{
	int32_t	num;
	int32_t	sign;

	num = 0;
	str += ft_skip_blanks(str);
	sign = ('-' == *str) ? -1 : 1;
	if ('-' == *str || '+' == *str)
		++str;
	while (F_ISDIGIT(*str))
		num = num * 0xA + *(str++) - 0x30;
	return (num * sign);
}
