/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:50:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/11 23:45:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	*ft_memdup(const void *restrict src, size_t size)
{
	void	*out;

	out = ft_memalloc(size);
	return (ft_memcpy(out, src, size));
}
