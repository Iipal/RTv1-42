/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:59:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 20:15:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_H
# define LIBFTSDL_H

# include "../../frameworks/SDL2.framework/Headers/SDL.h"
# include <stdint.h>

void	sdl_pixelput(SDL_Surface *surface, int32_t x, int32_t y, int64_t color);

#endif
