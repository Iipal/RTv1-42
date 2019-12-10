/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:33:11 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 09:34:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	*ft_memalloc(size_t size)
{
	void	*out;

	out = NULL;
	if (size)
	{
		if (!(out = malloc(size)))
			return (out);
		ft_memset(out, 0, size);
	}
	return (out);
}
