/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:39:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/18 01:09:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *restrict str)
{
	const size_t	real_end = ft_strlen(str);
	size_t			start;
	size_t			end;

	start = ~0UL;
	end = real_end;
	while (real_end / 2L > ++start)
		ft_swap(&str[start], &str[--end]);
}
