/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:39:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:07:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(string str)
{
	size_t			end;
	size_t			start;
	const size_t	real_end = ft_strlen(str);

	start = ~0L;
	end = real_end;
	while (++start < real_end / 2)
		ft_cwap(&str[start], &str[--end]);
}
