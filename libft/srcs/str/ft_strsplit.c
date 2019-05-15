/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:58:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/15 18:51:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ss_words(cstring str, string ch)
{
	size_t	counter;
	bool	is_word;

	counter = 0;
	is_word = false;
	while (*str)
	{
		if (is_word && *str == *ch)
			is_word = true;
		if (!is_word && *str != *ch)
		{
			++counter;
			is_word = false;
		}
		++str;
	}
	return (counter);
}

static size_t	ft_ss_wlen(cstring str, char ch)
{
	size_t	len;

	len = 0;
	while (*str && *str++ != ch)
		++len;
	return (len);
}

strtab			ft_strsplit(char const *s, char c)
{
	strtab	out;
	size_t	w_counter;
	size_t	i;

	i = 0;
	NO_R(s, NULL);
	w_counter = ft_ss_words(s, &c);
	NO_R(out = (strtab)malloc(sizeof(string) * (w_counter + 1)), NULL);
	while (w_counter--)
	{
		while (*s == c && *s != '\0')
			++s;
		out[i] = ft_strsub(s, 0, ft_ss_wlen(s, c));
		NO_R(out[i], NULL);
		s += ft_ss_wlen(s, c);
		++i;
	}
	out[i] = NULL;
	return (out);
}
