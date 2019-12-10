/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 13:58:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 12:01:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_ss_words(const char *s, int32_t c)
{
	size_t	counter;
	bool	is_word;

	counter = 0UL;
	is_word = false;
	while (s && *s)
	{
		if (is_word && *s == c)
			is_word = true;
		if (!is_word && *s != c)
		{
			++counter;
			is_word = false;
		}
		++s;
	}
	return (counter);
}

static inline size_t	ft_ss_wlen(char *restrict s, int32_t c)
{
	const char *restrict	ch = ft_strchr(s, c);

	return (ch ? (size_t)(ch - s) : ft_strlen(s));
}

char					**ft_strsplit(char *s, int32_t c)
{
	char	**out;
	size_t	w_counter;
	size_t	i;

	i = ~0UL;
	w_counter = ft_ss_words(s, c);
	out = (char**)ft_memalloc(sizeof(char*) * (w_counter + 1));
	while (w_counter--)
	{
		s = ft_strchr(s, c);
		out[++i] = ft_strndup(s, ft_ss_wlen(s, c));
		if (!out[i])
			return (NULL);
		s += ft_ss_wlen(s, c);
	}
	out[i] = NULL;
	return (out);
}
