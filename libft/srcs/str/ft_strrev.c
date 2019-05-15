/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:39:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/15 17:53:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	ft_strrev(string str)
{
	size_t	end;
	size_t	start;
	size_t	real_end;

	start = ~0L;
	end = ft_strlen(str);
	real_end = end;
	while (++start < real_end / 2)
		ft_cwap(&str[start], &str[--end]);
}
