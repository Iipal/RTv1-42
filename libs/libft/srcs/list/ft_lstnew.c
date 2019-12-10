/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:20:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/14 16:58:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list	*ft_lstnew(void const *restrict data, const size_t data_size)
{
	t_list	*out;

	if (!(out = (t_list*)ft_memalloc(sizeof(t_list))))
		return (out);
	if (!data)
		*out = (t_list) { NULL, 0UL, NULL };
	else
	{
		if (!(out->data = (t_list*)ft_memalloc(sizeof(data))))
		{
			free(out);
			return (NULL);
		}
		ft_memcpy(out->data, data, data_size);
		out->data_size = data_size;
	}
	out->next = NULL;
	return (out);
}
