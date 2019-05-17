/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:20:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:08:33 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strrepchr(const string str,
			const char search,
			const char replace)
{
	string ptr;

	NO_F(str);
	ptr = (string)str;
	while ((ptr = ft_strchr(ptr, search)))
		*ptr++ = replace;
	return (true);
}
