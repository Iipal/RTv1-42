/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:08:05 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/18 15:27:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEM_H
# define LIBFT_MEM_H

# include <string.h>
# include <stdint.h>
# include <stdlib.h>

/*
**	\return \param dest where fills the first \param len bytes of
**	 \param dest with the \param c.
*/
void		*ft_memset(void *restrict dest, int32_t c, size_t len);

/*
**	\return \param dest where copies \param n bytes from
**	 \param src to \param dest.
*/
void		*ft_memcpy(void *restrict dest,
				const void *restrict src,
				size_t n);

/*
**	\return \param dest where copies no more than \param n bytes from
**	 \param src to \pararm dest, stopping when the symbol \param c is found.
*/
void		*ft_memccpy(void *restrict dest,
				const void *restrict src,
				uint8_t c,
				size_t n);

/*
**	\return \param dest where copies
**	\param len bytes from \param src to \param dest.
*/
void		*ft_memmove(void *restrict dest,
				const void *restrict src,
				size_t len);

/*
**	\return matching byte of \param s after scans the initial \param n bytes
**	 of \param s for the first instance of c.
*/
void		*ft_memchr(const void *restrict ptr, int c, size_t n);

/*
**	Compares the first \param n bytes of \param s1 and \param s2.
**	\return an integer less than, equal to, or greater than zero
**	 if the first \param n bytes of \param s1 is found,
**	 respectively, to be less than, to match,
**	 or be greater than the first \param n bytes of \param s2.
*/
int32_t		ft_memcmp(const void *restrict s1,
				const void *restrict s2,
				size_t n);

/*
**	Erases the data in the \param n bytes of \param s,
**	 by writing zeros('\0') to that area.
*/
extern void	ft_bzero(void *restrict s, size_t n);

/*
**	Free memory at pointer \param ap.
*/
extern void	ft_memdel(void **ap);

/*
**	\return pointer to allocated \param size bytes.
*/
extern void	*ft_memalloc(size_t size);

/*
**	\return pointer to re-allocated of \param new_size pointer size
**  and copy \param old_size bytes from \param ptr to \return pointer.
*/
void		*ft_memrealloc(void *restrict ptr,
				size_t old_size,
				size_t new_size);

/*
**	Creating duplicate of \param src on heap.
*/
extern void	*ft_memdup(const void *restrict src, size_t size);

/*
**	Swap \param a and \param b where both of them is pointer to
**	 \param len bytes data-type.
*/
extern void	ft_memswap(void *restrict a, void *restrict b, size_t len);

#endif
