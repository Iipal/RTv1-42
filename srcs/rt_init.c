/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:22:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/29 17:47:10 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline bool	add_load_textures(Object *restrict const objs,
									const size_t ins_objs,
									const SDL_PixelFormat *format)
{
	const string	texs[] = {TEX_SPHERE};
	size_t			i;

	i = ~0L;
	while (ins_objs > ++i)
	{
		objs[i].texture = NULL;
		NO_F(objs[i].texture = sdl_load_image(*texs, format, objs[i].texture));
	}
	return (true);
}

inline bool			rt_init(Environment *restrict env)
{
	MEM(Sdl, env->sdl, 1, E_ALLOC);
	NODO_F(sdl_init(env->sdl, WIN_X, WIN_Y, RTV1_TITLE), rt_free(&env));
	env->cam_speed = MOVE_SPEED_PERCENT_DEFAULT;
	env->flags = (Flags){DEF_VIEWPORT_SCALE,
						DEF_SHADOW_BRIGHT,
						DEF_FPS_TEXT_COLOR, false,
						DEF_FPS_REFRESH_TIMER, false,
						DEF_DEBUG_MODE,
						DEF_NOT_CALC_LIGHT,
						DEF_PRINT_USAGE,
						DEF_TEXTURED};
	NO_F(add_load_textures(env->scene.objs, env->scene.ins_objs,
		env->sdl->wsurf->format));
	return (true);
}
