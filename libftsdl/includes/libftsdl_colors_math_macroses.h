/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl_colors_math_macroses.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:22:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/17 12:38:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_COLORS_MATH_MACROSES_H
# define LIBFTSDL_COLORS_MATH_MACROSES_H

# define COLOR_MAX  255
# define COLOR_MIN  0

# define RGB_BLACK  0x00
# define RGB_WHITE  0xffffff

# define CLR_BLACK (Color){0, 0, 0}
# define CLR_WHITE (Color){255, 255, 255}

# define INRANGE(c)	sdl_clr_inrange(c)

# define SDL_CLR_CMP(clr, u) (clr.r == u && clr.g == u && clr.b == u)
# define SDL_CLRS_CMP(c1, c2) (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b)

# define SDL_CLR_ISONE(clr, u) (clr.r == u || clr.g == u || clr.b == u)
# define SDL_CLRS_ISONE(c1, c2) (c1.r == c2.r || c1.g == c2.g || c1.b == c2.b)

# define SDL_CLR_TO_RGB(clr) (clr.r << 16 | clr.g << 8 | clr.b)
# define SDL_RGB_TO_CLR(hex) (Color){hex >> 16, (hex >> 8)  & 0xff, hex & 0xff}
# define SDL_HEX_TO_CLR(h)   (SDL_Color){h >> 16, (h >> 8)  & 0xff, h & 0xff, 0}

# define SDL_CLR_ADD(c, a) (Color){INRANGE(c.r+a),INRANGE(c.g+a),INRANGE(c.b+a)}
# define SDL_CLR_SUB(c, a) (Color){INRANGE(c.r-a),INRANGE(c.g-a),INRANGE(c.b-a)}

# define COLOR  typedef struct s_color  Color;
# define FCOLOR typedef struct s_fcolor FColor;

#endif
