/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_one_of_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 08:33:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/19 22:28:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t __attribute__((__overloadable__))
	ft_is_one_of_n(char cmp, size_t n, ...)
{
	va_list	ap;
	size_t	i;

	i = 0UL;
	va_start(ap, n);
	while (n-- && ++i)
		if (cmp == va_arg(ap, int))
		{
			va_end(ap);
			return (i);
		}
	va_end(ap);
	return (0UL);
}

size_t __attribute__((__overloadable__))
	ft_is_one_of_n(int cmp, size_t n, ...)
{
	va_list	ap;
	size_t	i;

	i = 0UL;
	va_start(ap, n);
	while (n-- && ++i)
		if (cmp == va_arg(ap, int))
		{
			va_end(ap);
			return (i);
		}
	va_end(ap);
	return (0UL);
}

size_t __attribute__((__overloadable__))
	ft_is_one_of_n(long cmp, size_t n, ...)
{
	va_list	ap;
	size_t	i;

	i = 0UL;
	va_start(ap, n);
	while (n-- && ++i)
	{
		if (cmp == va_arg(ap, long))
		{
			va_end(ap);
			return (i);
		}
	}
	va_end(ap);
	return (0UL);
}

size_t __attribute__((__overloadable__))
	ft_is_one_of_n(const char *restrict cmp, size_t n, ...)
{
	va_list	ap;
	size_t	i;

	i = 0UL;
	va_start(ap, n);
	while (n-- && ++i)
		if (!ft_strcmp(cmp, va_arg(ap, char*)))
		{
			va_end(ap);
			return (i);
		}
	va_end(ap);
	return (0UL);
}

size_t __attribute__((__overloadable__))
	ft_is_one_of_n(const char *restrict cmp, size_t cmp_len, size_t n, ...)
{
	va_list	ap;
	size_t	i;

	i = 0UL;
	va_start(ap, n);
	while (n-- && ++i)
		if (!ft_strncmp(cmp, va_arg(ap, char*), cmp_len))
		{
			va_end(ap);
			return (i);
		}
	va_end(ap);
	return (0UL);
}
