/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:20:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/18 00:41:50 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strrepchr(char *restrict str, int32_t s, int32_t r)
{
	char *ptr;

	ptr = str;
	if (!ptr)
		return (false);
	while ((ptr = ft_strchr(ptr, s)))
		*ptr++ = (char)r;
	return (true);
}
