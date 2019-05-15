/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:06:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/15 18:48:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STR_H
# define LIBFT_STR_H

# include <string.h>
# include "libft_macroses.h"

/*
**	Free memory for string and set \param as to NULL.
**	\param as pointer to string.
*/
extern void		ft_strdel(string *as);

/*
**	Reverse string \param str.
*/
extern void		ft_strrev(string str);

/*
**	Replace all \param search symbols in string \param str to \param replace.
*/
extern bool		ft_strrepchr(cstring str,
					const char search,
					const char replace);

/*
**	Convert string \param str to int32_t number.
**	\return 0 if string \param str is invalid,
**	 else - number which contained in string.
*/
extern int32_t	ft_atoi(string str);

/*
**	Convert string \param str to int64_t number.
**	\return 0 if string \param str is invalid,
**	 else - number which contained in string.
*/
extern int64_t	ft_atol(string str);

/*
**	Convert string \param str to int32_t number in \param base notation.
**	\return 0 if string \param str is invalid,
**	 else - number which contained in string converted in \param base notation.
*/
extern int32_t	ft_atoi_base(cstring str, int8_t base);

/*
**	Compare string \param s1 with \param s2.
**	\return difference of not matching symbols or 0 if strings equal.
*/
extern int8_t	ft_strcmp(cstring s1, cstring s2);

/*
**	Compare string \param s1 with \param s2 by \param n symbols.
**	\return difference of not matching symbols or 0 if strings equal.
*/
extern int8_t	ft_strncmp(cstring s1, cstring s2, size_t n);

/*
**	\return lenght of string \param str.
*/
extern size_t	ft_strlen(cstring str);

/*
**	Appends the NUL-terminated string \param src to the end of \param dest.
**	It will append at most \param dstsize - ft_strlen(\param dst) - 1 bytes,
**	 NUL-terminating the result.
*/
extern size_t	ft_strlcat(string dest, cstring src, size_t dstsize);

/*
**	Copies up to \param dstsize - 1 symbols from the NUL-terminated
**	 string \param str to \param dest, NUL-terminating the result.
*/
extern size_t	ft_strlcpy(string dest, cstring str, size_t dstsize);

/*
**	\return convert number \param n to string.
*/
extern string	ft_itoa(int32_t n);

/*
**	\return converted string \str alphabet symbols to lower case.
*/
extern string	ft_strlwr(string str);

/*
**	\return converted string \str alphabet symbols to upper case.
*/
extern string	ft_strupr(string str);

/*
**	\return new allocated copy string \param src
**	 or NULL if something went wrong.
*/
extern string	ft_strdup(cstring src);

/*
**	\return new allocated copied \param n symbols from string \param src
**	 or NULL if something went wrong.
*/
extern string	ft_strndup(cstring s1, size_t n);

/*
**	Copy string \param str to \param dest.
**	\return \param dest.
*/
extern string	ft_strcpy(string dest, cstring str);

/*
**	Copy \param len of \param src to \param dest.
**	\return \param dest.
*/
extern string	ft_strncpy(string dest, cstring src, size_t len);

/*
**	Appends string \param src to \param dest.
**	\return \param dest.
*/
extern string	ft_strcat(string dest, cstring src);

/*
**	Appends \param n symbols from string \param src to \param dest.
**	\return \param dest.
*/
extern string	ft_strncat(string dest, cstring src, size_t n);

/*
** \return a pointer to the first occurrence of the character \param c
**	 in the string \param s.
*/
extern string	ft_strchr(cstring s, uchar c);

/*
**	\return a pointer to the last occurrence of the character \param c
**	 in the string \param s
*/
extern string	ft_strrchr(cstring s, uchar c);

/*
** \return the first occurrence of the substring \param to_find
**  in the string \param str.
*/
extern string	ft_strstr(cstring str, cstring to_find);

/*
** \return the first occurrence of the null-termi-nated string
**	 \param to_find in the string \param str,
**	 where not more than \param len characters are searched.
*/
extern string	ft_strnstr(cstring str, cstring to_find, size_t len);

/*
**	\return allocate null-termi-nated string.
*/
extern string	ft_strnew(size_t size);

/*
**	\return allocate a “fresh” substring from the string \param s argument.
**	 The substring begins at index \param start and is of size \param len.
**	 If \param start and \param len aren’t refering to a valid substring,
**	 the behavior is undefined. If the allocation fails, returns NULL.
*/
extern string	ft_strsub(char const *s, uint32_t start, size_t len);

/*
**	\return allocate a “fresh” string ending with ’\0’,
**	 result of the concatenation of \param s1 and \param s2.
**	 If the allocation fails the function returns NULL.
*/
extern string	ft_strjoin(char const *s1, char const *s2);

/*
**	\return allocate a copy of the string \param s without whitespaces
**	 at the beginning or at the end of the string.
**	 Will be considered as whitespaces the following characters ’ ’, ’\n’, ’\t’.
**	 If s has no whitespaces at the beginning or at the end,
**	 the function returns a copy of \param s.
**	 If the allocation fails the function returns NULL.
*/
extern string	ft_strtrim(char const *s);

/*
** \return allocate an array of “fresh” strings (all ending with ’\0’,
**	 including the array itself) obtained by spliting \param s
**	 using the character \param c as a delimiter.
**	 If the allocation fails the function returns NULL.
*/
extern strtab	ft_strsplit(char const *s, char c);

#endif
