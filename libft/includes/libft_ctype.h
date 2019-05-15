/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ctype.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:04:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/15 17:51:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CTYPE_H
# define LIBFT_CTYPE_H

# include "libft_macroses.h"

/*
**	\param c - unsigned char.
**	\return true if \ref c is ASCII alphabet symbol, else - false.
*/
extern bool		ft_isalpha(const uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is ASCII digit, else - false.
*/
extern bool		ft_isdigit(const uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is ASCII alphabet symbol or is ASCII digit,
**	 else - false.
*/
extern bool		ft_isalnum(const uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is lower ASCII symbol, else - false.
*/
extern bool		ft_isascii(const uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is ASCII printable symbol, else - false.
*/
extern bool		ft_isprint(const uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is lower case ASCII alphabet symbol, else - false.
*/
extern bool		ft_islower(const uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is upper case ASCII alphabet symbol, else - false.
*/
extern bool		ft_isupper(const uchar c);

/*
**	\param c - unsigned char.
**	\return true if \ref c is '\t' '\n' '\v' '\f' '\r' or ' ', else - false.
*/
extern bool		ft_isblank(const uchar c);

/*
**	\param c - unsigned char.
**	\return If \ref c is lower case ASCII alphabet symbol
**	 return this symbol in upper case.
*/
extern uchar	ft_toupper(const uchar c);

/*
**	\param c - unsigned char.
**	\return If \ref c is upper case ASCII alphabet symbol
**	 return this symbol in lower case.
*/
extern uchar	ft_tolower(const uchar c);

#endif
