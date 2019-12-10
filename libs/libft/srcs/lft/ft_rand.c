/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 01:54:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 09:52:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline size_t	ft_rand(size_t limit)
{
	size_t			ponies;
	const int32_t	fd = open("/dev/urandom", O_RDONLY);

	read(fd, &ponies, sizeof(size_t));
	close(fd);
	return (ponies % limit);
}
