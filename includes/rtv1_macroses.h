/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_macroses.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:12:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 14:26:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_MACROSES_H
# define RTV1_MACROSES_H

/*
**	Print \param msg to stdout.
*/
# define MSG(msg) ft_putstr(msg)

/*
**	Print \param msg to stdout followed by newline at end.
*/
# define MSGN(msg) ft_putendl(msg)

/*
**	If \param ex false:
**	 Print \param msg followed by newline at end.
**	 \param do something.
**	 \param ret return value.
*/
# define NOTIS(msg, ex, do, ret) if (!(ex)) {MSGN(msg);do;return(ret);}
/*
**	If \param ex false return false.
*/
# define NOTIS_F(ex) if (!(ex)) return (false)

/*
**	Used for validate argmunets count;
**	\param ac: Arguments counter.
**	\param av: Arguments array.
*/
# define ISARGS(ac, av) {--ac;++av; NOTIS(E_USAGE, !(ac != 1), exit(-1), 0);}
/*
**	Called ft_bzero(\param dest, size of \param type multiply by \param x).
*/
# define Z(type, dest, x) ft_bzero(dest, sizeof(type) * (x))

/*
**	Allocating memroy and set all values to zero by calling Z macros.
**	 \param t data type.
**	 \param d destination variable.
**	 \param x counter how much \param t memory needed to allocate.
*/
# define ISZ(t, d, x) NOTIS_F(d = (t*)malloc(sizeof(t)*(x))); Z(t, d, x)

/*
**	If \param trash isnt NULL:
**	 Free memory with \param del function call.
**	 And set \param trash to NULL.
*/
# define FREE(trash, del) if ((trash)) {del(trash); trash = NULL;}
/*
**	--------------
**	Math macroses:
**	--------------
*/

/*
**	Absolute value of \param var macros.
*/
# define ABS(var) ((var) < 0) ? -(var) : (var)

#endif
