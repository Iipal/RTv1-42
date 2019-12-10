/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:39:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 12:06:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	ft_putendl_fd(const char *restrict s, int32_t fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}