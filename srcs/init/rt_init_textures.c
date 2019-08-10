/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 20:57:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/10 09:26:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

bool	rt_init_textures(Object *restrict const objs,
			size_t const ins_objs,
			SDL_PixelFormat const *format)
{
	size_t						i;
	const char *restrict const	textures_path[TEX_MAX] = {TEX_WORLD, TEX_WOOD,
		TEX_RUBBLE};

	i = ~0UL;
	while (ins_objs > ++i)
		NO_F(objs[i].texture = sdl_load_image(textures_path[ft_rand(TEX_MAX)],
									format));
	return (true);
}
