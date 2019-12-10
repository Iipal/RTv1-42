/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:01:32 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 11:30:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline char	*ft_strndup(const char *restrict src, size_t n)
{
	return (ft_strncpy(ft_strnew(sizeof(char) * n), src, n));
}
