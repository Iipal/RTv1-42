/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_errno.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:05:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/10 15:45:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_ERRNO_H
# define RTV1_ERRNO_H

/*
**  Printed this message if not enought command line arguments for start game.
*/
# define E_USAGE    "Usage: ./RTv1 <scene_name>.rtv1"

/*
**  Printed this message if user trying to start game not from root folder.
*/
# define E_DIR      " ERROR: Invalid executable path."

/*
**  Printed this mesage if allocating memory is failed.
*/
# define E_ALLOC    " ERROR: Where is memory, pal ?"

# define E_SURFPXL  " ERROR: Broken SDL_Surface load. ->pixels not found"

#endif
