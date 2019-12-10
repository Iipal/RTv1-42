/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_put.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:02:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/18 00:29:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PUT_H
# define LIBFT_PUT_H

# include "libft_macroses.h"

/*
**	Put \param c char to stdout.
*/
extern void	ft_putchar(int32_t c);
# define F_PUTCHAR(c) write(1, &(c), 1)

/*
**	Put \param c char to stdout by \param n times.
*/
void		ft_putnchar(int32_t c, size_t n);

/*
**	Put \param s string to stdout.
*/
void		ft_putstr(const char *restrict s);

/*
**	Put \param s string to stdout followed by newline.
*/
extern void	ft_putendl(const char *restrict s);

/*
**	Put \param n number to stdout.
*/
void		ft_putnbr(int64_t n);

/*
**	Put \param c char to specified \param fd output.
*/
extern void	ft_putchar_fd(int32_t c, int32_t fd);
# define F_PUTCHAR_FD(c, fd) write(fd, &(c), 1)

/*
**	Put \param s string to specified \param fd output.
*/
void		ft_putstr_fd(const char *restrict s, int32_t fd);

/*
**	Put \param s string to specified \param fd output followed by newline.
*/
void		ft_putendl_fd(const char *restrict s, int32_t fd);

/*
**	Put number \param n
*/
void		ft_putnbr_fd(int64_t n, int32_t fd);

/*
**	Print all strings from \param file to stdout or return false.
*/
bool		ft_putfile(const char *restrict file);

#endif
