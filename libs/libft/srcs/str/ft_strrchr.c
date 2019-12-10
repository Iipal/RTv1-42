/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:07:43 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 12:00:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *restrict str, int32_t c)
{
	size_t	len;

	len = ft_strlen(str);
	while (len && str[len] != c)
		--len;
	return ((c == str[len]) ? &str[len] : NULL);
}
