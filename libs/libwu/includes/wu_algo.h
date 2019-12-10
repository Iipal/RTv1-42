/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:17:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/10 17:43:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WU_ALGO_H
# define WU_ALGO_H

# include <SDL2/SDL.h>
# include "libft.h"

typedef struct s_2df
{
	float	x;
	float	y;
}				s2df;

void	wu_draw_line(s2df xy0, s2df xy1, SDL_Surface *restrict surf);

#endif
