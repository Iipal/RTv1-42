/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:03:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 11:29:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline char	*ft_strdup(const char *restrict src)
{
	return (ft_strcpy(ft_strnew(sizeof(char) * ft_strlen(src)), src));
}
