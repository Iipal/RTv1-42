/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:39:56 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 13:41:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_lstdel(t_list **alist, void (*del)(void*, size_t))
{
	if ((*alist)->next)
		ft_lstdel(&((*alist)->next), del);
	ft_lstdelone(alist, del);
}
