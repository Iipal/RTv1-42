/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:21:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/28 22:59:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_putfile(string file)
{
	const int32_t	fd = open(file, O_RDONLY);
	string			temp;

	temp = NULL;
	if (fd < 0)
		return (false);
	while (ft_gnl(fd, &temp) > 0)
	{
		ft_putendl(temp);
		ft_strdel(&temp);
	}
	close(fd);
	return (true);
}
