/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:32:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/26 11:35:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *restrict str, size_t max_len)
{
	size_t	i;

	i = ~0UL;
	while (max_len > ++i)
		if (!str[i])
			break ;
	return (i);
}
