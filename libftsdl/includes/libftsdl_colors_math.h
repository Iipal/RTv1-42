/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl_colors_math.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:24:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/10 18:23:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_COLORS_MATH_H
# define LIBFTSDL_COLORS_MATH_H

# include "../../libft/includes/libft.h"

# ifdef __APPLE__
#  include "../frameworks/SDL2.framework/Headers/SDL.h"
#  include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# endif
# ifdef __linux__
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_ttf.h>
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

# define COLOR_MULT(c1, cp1, i) *sdl_clrs_add(&c1, *sdl_clr_mul(&cp1, i))

# define SDL_CLR_CMP(clr, u) (clr.r == u && clr.g == u && clr.b == u)
# define SDL_CLRS_CMP(c1, c2) (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b)

# define SDL_CLR_ISONE(clr, u) (clr.r == u || clr.g == u || clr.b == u)
# define SDL_CLRS_ISONE(c1, c2) (c1.r == c2.r || c1.g == c2.g || c1.b == c2.b)

Uint8	sdl_clr_inrange(int16_t color);

Uint32	sdl_clr_convert_rgb(Color src);
Color	sdl_rgb_convert_clr(Uint32 src);

Color	*sdl_clr_bright_inc(Color *dst, float percent);
Color	*sdl_clr_bright_dec(Color *dst, float percent);

Color	*sdl_clr_add(Color *dst, const int16_t add);
Color	*sdl_clr_sub(Color *dst, const int16_t sub);
Color	*sdl_clr_div(Color *dst, const float div);
Color	*sdl_clr_mul(Color *dst, const float mul);

Color	*sdl_clrs_gradient(const Color start, const Color end, int32_t len);

void	sdl_clrs_swap(Color *a, Color *b);

Color	*sdl_clrs_bright_inc(Color *dst, const Color src, float percent);
Color	*sdl_clrs_bright_dec(Color *dst, const Color src, float percent);

Color	*sdl_clrs_add(Color *dst, const Color add);
Color	*sdl_clrs_sub(Color *dst, const Color sub);
Color	*sdl_clrs_div(Color *dst, const Color div);
Color	*sdl_clrs_mul(Color *dst, const Color mul);

#endif
