/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_blanks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:42:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/16 16:44:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_skip_blanks(cstring str)
{
	size_t	i;

	i = 0;
	while (str[i] && ft_isblank(str[i]))
		++i;
	return (i);
}
