/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:37:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 13:39:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_lstdelone(t_list **alist, void (*del)(void*, size_t))
{
	del((*alist)->data, (*alist)->data_size);
	free(*alist);
	*alist = NULL;
}
