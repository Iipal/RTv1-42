/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:08:05 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 13:25:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEM_H
# define LIBFT_MEM_H

# include <string.h>

# include "libft_macroses.h"

/*
**	Erases the data in the \param n bytes of \param s,
**	 by writing zeros('\0') to that area.
*/
extern void		ft_bzero(pvoid s, const size_t n);

/*
**	Free memory at pointer \param ap.
*/
extern void		ft_memdel(pvoid *ap);

/*
**	\return \param dest where fills the first \param len bytes of
**	 \param dest with the \param c.
*/
pvoid			ft_memset(pvoid dest, const int32_t c, const size_t len);

/*
**	\return \param dest where copies \param n bytes from
**	 \param src to \param dest.
*/
pvoid			ft_memcpy(pvoid dest, const pvoid src, const size_t n);

/*
**	\return \param dest where copies no more than \param n bytes from
**	 \param src to \pararm dest, stopping when the symbol \param c is found.
*/
pvoid			ft_memccpy(pvoid dest,
					const pvoid src,
					uint8_t c,
					const size_t n);

/*
**	\return \param dest where copies
**	\param len bytes from \param src to \param dest.
*/
pvoid			ft_memmove(pvoid dest, void const *src, size_t len);

/*
**	\return matching byte of \param s after scans the initial \param n bytes
**	 of \param s for the first instance of c.
*/
pvoid			ft_memchr(const pvoid s, const uchar c, size_t n);

/*
**	\return pointer to allocated \param size bytes.
*/
extern pvoid	ft_memalloc(size_t size);

/*
**	Compares the first \param n bytes of \param s1 and \param s2.
**	\return an integer less than, equal to, or greater than zero
**	 if the first \param n bytes of \param s1 is found,
**	 respectively, to be less than, to match,
**	 or be greater than the first \param n bytes of \param s2.
*/
int32_t			ft_memcmp(const pvoid s1, const pvoid s2, size_t n);
#endif
