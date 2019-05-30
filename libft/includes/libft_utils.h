/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:09:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/31 00:07:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
# define LIBFT_UTILS_H

# include <string.h>

# include "libft_macroses.h"

/*
**	Reading file line by line. (Get Next Line)
**	\param fd: File descriptor.
**	\param line: pointer to string where will saved each line from file.
**	\return:
**	[0 - End of File.
**	 1 - Successful readed 1 line from file.
**	 -1 - Reading error.]
*/
int8_t	ft_gnl(const int32_t fd, string *line);

/*
**	Randomize unsigned decimal number.
**	\param limits: Max random number.
**	\return random: number from 0 to \ref limits.
*/
size_t	ft_rand(size_t limits);

/*
**	Compare if one of \param n va_list arguments is equal to \param cmp.
**	\param cmp: Value to compare.
**	\param n: va_list arguments counter to compare.
**	\param ...: va_list.
**	\return true if one of argument is equal to \param cmp, else - false.
*/
bool	ft_is_one_of_n(int64_t cmp, size_t n, ...);

/*
**	Compare if one of \param n va_list arguments is equal to \param cmp.
**	\param cmp: String to compare.
**	\param cmp_len: boolean for compare strings length or not.
**	\param n: va_list arguments counter to compare.
**	\param ...: va_list.
**	\return true if one of argument is equal to \param cmp, else - false.
*/
bool	ft_is_one_of_str(const string cmp, const bool cmp_len, size_t n, ...);

/*
**	\return How many digits in \param n.
*/
size_t	ft_digits(int32_t n);

/*
**	\return true is \param str contain only digits or false if not.
*/
bool	ft_isdigits_str(const string str);

/*
**	\return true is \param str contain only hex digits or false if not.
*/
bool	ft_ishex_str(string str);

/*
**	\return true is \param str contain only hex digits or false if not.
*/
bool	ft_isalpha_str(string str);

/*
**	\return true if \param n symbols in string \param str
**		contains only hex digits or false if not.
*/
bool	ft_ishex_strn(string str, size_t n);

/*
**	\return How many blanks skips in string \param str.
*/
size_t	ft_skip_blanks(const string str);

/*
**	\return How many symbols to first blank symbol in string \param str.
*/
size_t	ft_skip_to_blank(const string str);

/*
**	Swap int32_t values.
*/
void	ft_swap(int32_t *a, int32_t *b);

/*
**	Swap char values.
*/
void	ft_cwap(char *a, char *b);

#endif
