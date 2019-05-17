/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_put.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:02:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 12:58:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PUT_H
# define LIBFT_PUT_H

# include "libft_macroses.h"

/*
**	Put \param c char to stdout.
*/
void	ft_putchar(const uchar c);

/*
**	Put \param s string to stdout.
*/
void	ft_putstr(char const *s);

/*
**	Put \param s string to stdout followed by newline.
*/
void	ft_putendl(char const *s);

/*
**	Put \param n number to stdout.
*/
void	ft_putnbr(int32_t n);

/*
**	Put \param c char to specified \param fd output.
*/
void	ft_putchar_fd(const uchar c, int32_t fd);

/*
**	Put \param s string to specified \param fd output.
*/
void	ft_putstr_fd(char const *s, int32_t fd);

/*
**	Put \param s string to specified \param fd output followed by newline.
*/
void	ft_putendl_fd(char const *s, int32_t fd);

/*
**	Put number \param n
*/
void	ft_putnbr_fd(int32_t n, const int32_t fd);

/*
**	Print all strings from \param file to stdout or return false.
*/
bool	ft_putfile(string file);

#endif
