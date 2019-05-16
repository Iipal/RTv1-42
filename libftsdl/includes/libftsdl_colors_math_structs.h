/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl_colors_math_structs.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:24:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/16 18:03:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_COLORS_MATH_STRUCTS_H
# define LIBFTSDL_COLORS_MATH_STRUCTS_H

# include <stdint.h>
# include <math.h>

struct	s_color
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
};

struct	s_fcolor
{
	double_t	r;
	double_t	g;
	double_t	b;
};

#endif
