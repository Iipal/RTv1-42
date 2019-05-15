/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_put.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:02:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/15 17:44:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PUT_H
# define LIBFT_PUT_H

# include "libft_macroses.h"

/*
**	Put \param c char to stdout.
*/
extern void	ft_putchar(const uchar c);

/*
**	Put \param s string to stdout.
*/
extern void	ft_putstr(char const *s);

/*
**	Put \param s string to stdout followed by newline.
*/
extern void	ft_putendl(char const *s);

/*
**	Put \param n number to stdout.
*/
extern void	ft_putnbr(int32_t n);

/*
**	Put \param c char to specified \param fd output.
*/
extern void	ft_putchar_fd(const uchar c, int32_t fd);

/*
**	Put \param s string to specified \param fd output.
*/
extern void	ft_putstr_fd(char const *s, int32_t fd);

/*
**	Put \param s string to specified \param fd output followed by newline.
*/
extern void	ft_putendl_fd(char const *s, int32_t fd);

/*
**	Put number \param n
*/
extern void	ft_putnbr_fd(int32_t n, const int32_t fd);

/*
**	Print all strings from \param file to stdout or return false.
*/
extern bool	ft_putfile(string file);

#endif
