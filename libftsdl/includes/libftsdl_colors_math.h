/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl_colors_math.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:24:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/13 12:53:02 by tmaluh           ###   ########.fr       */
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
	float_t	r;
	float_t	g;
	float_t	b;
};

# define COLOR  typedef struct s_color  Color;
# define FCOLOR typedef struct s_fcolor FColor;

COLOR;
FCOLOR;

# define RGB_BLACK 0x00
# define RGB_WHITE 0xffffff

# define CLR_BLACK (Color){0, 0, 0}
# define CLR_WHITE (Color){255, 255, 255}

# define INRANGE(c)	sdl_clr_inrange(c)

# define SDL_CLR_CMP(clr, u) (clr.r == u && clr.g == u && clr.b == u)
# define SDL_CLRS_CMP(c1, c2) (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b)

# define SDL_CLR_ISONE(clr, u) (clr.r == u || clr.g == u || clr.b == u)
# define SDL_CLRS_ISONE(c1, c2) (c1.r == c2.r || c1.g == c2.g || c1.b == c2.b)

# define SDL_CLR_TO_RGB(clr) (clr.r << 16 | clr.g << 8 | clr.b)
# define SDL_RGB_TO_CLR(hex) (Color) {hex >> 16, (hex >> 8)  & 0xff, hex & 0xff}

# define SDL_CLR_ADD(c, a) (Color){INRANGE(c.r+a),INRANGE(c.g+a),INRANGE(c.b+a)}
# define SDL_CLR_SUB(c, a) (Color){INRANGE(c.r-a),INRANGE(c.g-a),INRANGE(c.b-a)}

Uint8	sdl_clr_inrange(const int16_t color);

Color	sdl_clr_bright_inc(Color src, const float_t percent);
Color	sdl_clr_bright_dec(Color src, const float_t percent);

Color	sdl_clr_div(Color src, const float_t div);
Color	sdl_clr_mul(Color src, const float_t mul);

void	sdl_clrs_swap(Color *a, Color *b);

Color	*sdl_clrs_gradient(Color start,
					const Color end,
					const size_t len);

Color	sdl_clrs_bright_inc(Color clr1,
						const Color clr2,
						const float_t percent);
Color	sdl_clrs_bright_dec(Color clr1,
						const Color clr2,
						const float_t percent);

Color	sdl_clrs_add(Color src, const Color add);
Color	sdl_clrs_sub(Color src, const Color sub);
Color	sdl_clrs_div(Color src, const Color div);
Color	sdl_clrs_mul(Color src, const Color mul);

#endif
