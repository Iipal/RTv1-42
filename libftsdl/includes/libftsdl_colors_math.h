/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl_colors_math.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:24:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/18 15:37:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_COLORS_MATH_H
# define LIBFTSDL_COLORS_MATH_H

# include "../../libft/includes/libft.h"

# ifdef __APPLE__
#  include "../../frameworks/SDL2.framework/Headers/SDL.h"
# endif
# ifdef __linux__
#  include <SDL2/SDL.h>
# endif

# define COLOR_MAX  255
# define COLOR_MIN  0

struct	s_color
{
	int16_t	r;
	int16_t	g;
	int16_t	b;
};

struct	s_fcolor
{
	float	r;
	float	g;
	float	b;
};

# define COLOR  typedef struct s_color  Color;
# define FCOLOR typedef struct s_fcolor FColor;

COLOR;
FCOLOR;

# define INRANGE(c)	sdl_clr_inrange(c)

Uint8	sdl_clr_inrange(int16_t color);

Uint32	sdl_clr_convert_rgb(Color src);
Color	sdl_rgb_convert_clr(Uint32 src);

Color	*sdl_clr_bright_inc(Color *dst, float percent);
Color	*sdl_clr_bright_dec(Color *dst, float percent);

bool	sdl_clr_isoneof(const Color c1, Uint8 c);
bool	sdl_clr_equal(const Color c1, Uint8 c);

Color	*sdl_clr_add(Color *dst, const int16_t add);
Color	*sdl_clr_sub(Color *dst, const int16_t sub);
Color	*sdl_clr_div(Color *dst, const float div);
Color	*sdl_clr_mul(Color *dst, const float mul);

Color	*sdl_clrs_gradient(const Color start, const Color end, int32_t len);

void	sdl_clrs_swap(Color *a, Color *b);

Color	*sdl_clrs_bright_inc(Color *dst, const Color src, float percent);
Color	*sdl_clrs_bright_dec(Color *dst, const Color src, float percent);

bool	sdl_clrs_isoneof(const Color c1, const Color c2);
bool	sdl_clrs_equal(const Color c1, const Color c2);

Color	*sdl_clrs_add(Color *dst, const Color add);
Color	*sdl_clrs_sub(Color *dst, const Color sub);
Color	*sdl_clrs_div(Color *dst, const Color div);
Color	*sdl_clrs_mul(Color *dst, const Color mul);

#endif
