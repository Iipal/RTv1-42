/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:50:28 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/19 00:06:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline void	rt_free(Environment * restrict* env)
{
	IFDO(*env && (*env)->sdl, sdl_free(&(*env)->sdl));
	IFDO(*env && (*env)->s.objs, FREE((*env)->s.objs, free));
	IFDO(*env && (*env)->s.l, FREE((*env)->s.l, free));
	FREE(*env, free);
}
