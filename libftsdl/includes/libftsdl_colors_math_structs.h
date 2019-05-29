/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl_colors_math_structs.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:24:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/29 12:00:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_COLORS_MATH_STRUCTS_H
# define LIBFTSDL_COLORS_MATH_STRUCTS_H

# include <stdint.h>
# include <math.h>

typedef struct		s_clr
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}					t_clr;

union				u_color
{
	uint32_t	hex;
	t_clr		c;
};

struct				s_fcolor
{
	double_t	r;
	double_t	g;
	double_t	b;
};

#endif
