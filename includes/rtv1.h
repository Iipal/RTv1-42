/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:02:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 12:14:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libftsdl.h"
# include "rtv1_errno.h"
# include "rtv1_structs.h"
# include "rtv1_macroses.h"
# include <math.h>

bool	rt_read_scene(Environment *env, string scene_file);
bool	rt_init(Environment *env);

void	rt_rendering(Environment *env);

void	rt_free(Environment **env);

#endif
