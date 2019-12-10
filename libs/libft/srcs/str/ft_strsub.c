/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:07:51 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 11:40:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline char	*ft_strsub(const char *restrict s, size_t start, size_t len)
{
	return (ft_strncpy(ft_strnew(len), s + start, len));
}
