/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ctype.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:04:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 10:07:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CTYPE_H
# define LIBFT_CTYPE_H

/*
**	\param c - int(always 32 bits).
**	\return true if \ref c is ASCII digit, else - false.
*/
extern bool		ft_isdigit(int32_t c);
# define F_ISDIGIT(c) ((c) >= 0x30 && (c) <= 0x39)

/*
**	\param c - int(always 32 bits).
**	\return true if \ref c is lower case ASCII alphabet symbol, else - false.
*/
extern bool		ft_islower(int32_t c);
# define F_ISLOWER(c) ((c) >= 0x61 && (c) <= 0x7A)

/*
**	\param c - int(always 32 bits).
**	\return true if \ref c is upper case ASCII alphabet symbol, else - false.
*/
extern bool		ft_isupper(int32_t c);
# define F_ISUPPER(c) ((c) >= 0x41 && (c) <= 0x5A)

/*
**	\param c - int(always 32 bits).
**	\return true if \ref c is ASCII alphabet symbol, else - false.
*/
extern bool		ft_isalpha(int32_t c);
# define F_ISALPHA(c) (F_ISLOWER(c) || F_ISUPPER(c))

/*
**	\param c - int(always 32 bits).
**	\return true if \ref c is ASCII alphabet symbol or is ASCII digit,
**	 else - false.
*/
extern bool		ft_isalnum(int32_t c);
# define F_ISALNUM(c) (F_ISDIGIT(c) || F_ISALPHA(c))

/*
**	\param c - int(always 32 bits).
**	\return true if \ref c is lower ASCII symbol, else - false.
*/
extern bool		ft_isascii(int32_t c);
# define F_ISASCII(c) ((c) >= 0x0 && (c) <= 0x7F)

/*
**	\param c - int(always 32 bits).
**	\return true if \ref c is ASCII printable symbol, else - false.
*/
extern bool		ft_isprint(int32_t c);
# define F_ISPRINT(c) ((c) >= 0x20 && (c) <= 0x7E)

/*
**	\param c - int(always 32 bits).
**	\return true if \ref c is '\t' '\n' '\v' '\f' '\r' or ' ', else - false.
*/
extern bool		ft_isblank(int32_t c);
# define F_ISBLANK(c) (((c) >= 0x9 && (c) <= 0xD) || (c) == 0x20)

/*
**	\param c - int(always 32 bits).
**	\return If \ref c is lower case ASCII alphabet symbol
**	 return this symbol in upper case.
*/
extern int32_t	ft_toupper(int32_t c);
# define F_TOUPPER(c) (F_ISLOWER(c) ? ((c) - 0x20) : (c))

/*
**	\param c - int(always 32 bits).
**	\return If \ref c is upper case ASCII alphabet symbol
**	 return this symbol in lower case.
*/
extern int32_t	ft_tolower(int32_t c);
# define F_TOLOWER(c) (F_ISUPPER(c) ? ((c) + 0x20) : (c))

#endif
