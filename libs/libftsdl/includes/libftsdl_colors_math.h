/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl_colors_math.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:24:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/05 12:25:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_COLORS_MATH_H
# define LIBFTSDL_COLORS_MATH_H

# include "libftsdl_colors_math_structs.h"
# include "libftsdl_colors_math_macroses.h"

# if defined __APPLE__ || defined __linux__
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_image.h>
#  include <SDL2/SDL_ttf.h>
# else
#  error "Unsupported OS. Try to compile this on MacOS or Linux"
# endif

COLOR;
FCOLOR;

Color	sdl_clr_bright_inc(Color const src, float_t const percent);
Color	sdl_clr_bright_dec(Color const src, float_t const percent);

Color	sdl_clr_add(Color const src, float_t const add);
Color	sdl_clr_sub(Color const src, float_t const sub);
Color	sdl_clr_div(Color const src, float_t const div);
Color	sdl_clr_mul(Color const src, float_t const mul);

Color	*sdl_clrs_gradient(Color const start, Color const end, size_t const n);

Color	sdl_clrs_bright_inc(Color const c1, Color const c2, float_t const per);
Color	sdl_clrs_bright_dec(Color const c1, Color const c2, float_t const per);

Color	sdl_clrs_add(Color const src, Color const add);
Color	sdl_clrs_sub(Color const src, Color const sub);
Color	sdl_clrs_div(Color const src, Color const div);
Color	sdl_clrs_mul(Color const src, Color const mul);

#endif
