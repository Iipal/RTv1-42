/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:33:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 13:38:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list*))
{
	t_list	*out;
	t_list	*l;

	if (!list)
		return (NULL);
	l = f(list);
	out = l;
	while (list->next)
	{
		list = list->next;
		if (!(l->next = f(list)))
		{
			free(l->next);
			return (NULL);
		}
		l = l->next;
	}
	return (out);
}
