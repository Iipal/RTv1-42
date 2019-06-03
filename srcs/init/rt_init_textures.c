/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 20:57:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/03 09:26:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline bool	rt_init_textures(Object *restrict const objs,
								const size_t ins_objs,
								const SDL_PixelFormat *format)
{
	size_t						i;
	const char *restrict const	textures_path[TEX_MAX] = {TEX_WORLD, TEX_WOOD,
		TEX_RUBBLE};

	i = ~0L;
	while (ins_objs > ++i)
		NO_F(objs[i].texture = sdl_load_image(textures_path[ft_rand(TEX_MAX)],
							format, objs[i].texture));
	return (true);
}
