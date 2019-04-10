/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:45:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 17:47:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_digits(int32_t n)
{
	string	temp;
	int32_t	len;

	temp = ft_itoa(n);
	len = ft_strlen(temp);
	ft_strdel(&temp);
	return (len);
}
