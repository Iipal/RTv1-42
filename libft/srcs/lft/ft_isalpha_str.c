/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:07:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/31 00:08:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isalpha_str(string str)
{
	size_t	i;

	i = ~0L;
	while (str[++i])
		if (!ft_isalpha(str[i]))
			return (false);
	return (true);
}
