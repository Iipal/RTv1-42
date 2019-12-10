/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:58:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/12 20:22:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	ft_memswap(void *restrict a, void *restrict b, size_t len)
{
	void	*c;

	c = ft_memdup(a, len);
	ft_memmove(a, b, len);
	ft_memmove(b, c, len);
	ft_memdel(&c);
}
