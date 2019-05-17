/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:33:11 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:25:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline pvoid	ft_memalloc(const size_t size)
{
	pvoid	out;

	out = NULL;
	if (size)
	{
		NO_R(out = malloc(size), out);
		ft_memset(out, 0, size);
	}
	return (out);
}
