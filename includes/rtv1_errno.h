/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_errno.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:05:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/17 14:14:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_ERRNO_H
# define RTV1_ERRNO_H

# define E_USAGE    "Usage: ./RTv1 <scene_name>.rtv1"

# define PERR       " ERROR"
# define ERR        " ERROR: "

# define E_DIR      ERR "Invalid executable path."
# define E_ALLOC    ERR "Where is memory, pal ?"

# define E_DUP      ERR "In scene cannot be more than 1 any object at once."

# define E_NOCAM    ERR "No camera in scene founded."
# define E_CAMDIR   ERR "Camera destination point not in available range."
# define E_CAMPOS   ERR "Camera position not in available range."
# define E_NOLIGHT  ERR "No origin light in scene founded."
# define E_LIGHTPOS ERR "Light position not in available range."
# define E_LINT     ERR "Light intensity not in available range."
# define E_SPPOS    ERR "Sphere position not in available range."
# define E_SPRAD    ERR "Sphere radius not in available range."
# define E_SPSPEC   ERR "Sphere specular intensity not in available range."

# define E_FNLESS   ERR "Too short file name."
# define E_FILEXT   ERR "Invalid scene file extension. (.rtv1)"
# define E_ISYNTAX  ERR "Invalid scene file syntax."

# define E_AT		" Error occured at line: "
# define ERR_AT_NL(nl) MSG(E_AT);ft_putnbr(nl);
# define ERRAT(nl, msg) {ERR_AT_NL(nl);MSG(" \"");MSG(msg);MSGN("\"");}

#endif
