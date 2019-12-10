/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl_macroses.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:20:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 18:59:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_MACROSES_H
# define LIBFTSDL_MACROSES_H

# define FPS_FONT "./libs/libftsdl/resources/fonts/04B_03__.TTF"
# define FPS_FONT_SIZE 18

# define CONVERT_FROM_CANVAS(x, y, win_x, win_y) (__v2si){x+win_x/2, y+win_y/2}
# define D_FROM_CANVAS(x, y, wx, wy) (t_v2df){(x)+((wx)/2),(y)+((wy)/2)}

# ifndef __APPLE__
#  define NON_NULL(p) __nonnull(p)
# else
#  define NON_NULL(p)
# endif

#endif
