/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_macroses.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:12:55 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 11:23:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_MACROSES_H
# define RTV1_MACROSES_H

# define RTV1_TITLE     "Ray Tracing v1"
# define RTV1_EXE_PATH  "./RTv1"
# define RTV1_FILEXT    ".rtv1"

# define WIN_MIN_X	400
# define WIN_MIN_Y	400

# ifdef __APPLE__
#  define WIN_MAX_X 2000
#  define WIN_MAX_Y 1000
# endif

# ifdef __linux__
#  define WIN_MAX_X 1000
#  define WIN_MAX_Y 500
# endif

# define RGB_BLACK	0x00

#endif
