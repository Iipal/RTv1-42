/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl_colors_math_structs.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:24:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 12:26:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_COLORS_MATH_STRUCTS_H
# define LIBFTSDL_COLORS_MATH_STRUCTS_H

# include <stdint.h>
# include <math.h>

struct	s_color
{
	int16_t	r;
	int16_t	g;
	int16_t	b;
};

struct	s_fcolor
{
	float_t	r;
	float_t	g;
	float_t	b;
};

#endif
