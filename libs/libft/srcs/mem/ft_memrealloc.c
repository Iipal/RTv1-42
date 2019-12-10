/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:16:23 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/18 15:27:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *restrict ptr, size_t old_size, size_t new_size)
{
	void	*out;

	out = NULL;
	if (!new_size)
	{
		free(ptr);
		return (out);
	}
	else if (!ptr)
		return (ft_memalloc(new_size));
	else if (new_size <= old_size)
		return (ptr);
	else
	{
		if ((out = ft_memalloc(new_size)))
		{
			ft_memcpy(out, ptr, old_size);
			free(ptr);
		}
	}
	return (out);
}
