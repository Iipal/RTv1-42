/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:45:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/16 16:45:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_digits(int32_t n)
{
	string	temp;
	size_t	len;

	temp = ft_itoa(n);
	len = ft_strlen(temp);
	ft_strdel(&temp);
	return (0 > n ? 1 + len : len);
}
