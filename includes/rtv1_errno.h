/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_errno.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:05:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/07 01:54:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_ERRNO_H
# define RTV1_ERRNO_H

# define E_USAGE    "Usage: ./RTv1 <scene_name>.rtv1"

# define PERR       " ERROR"
# define ERR        " ERROR: "

# define E_FNMAE    ERR "Missing file name."
# define E_EFILE    ERR "Empty scene file."
# define E_FILEXT   ERR "Invalid scene file extension. (.rtv1)"
# define E_ISYNTAX  ERR "Invalid scene file syntax."

# define E_DIR      ERR "Invalid executable path."
# define E_ALLOC    ERR "Where is memory, pal ?"

# define E_OBJ      ERR "Unknown object type."

# define E_DUP      ERR "In scene cannot be more than "
# define E_DCAMERA  E_DUP "1 camera."
# define E_DLIGHT   E_DUP "1 light origin."

# define E_NOCAM    ERR "No camera in scene founded."
# define E_NOLIGHT  ERR "No origin light in scene founded."

# define E_INRANGE  "not in available range."

# define E_CAMDIR   ERR "Camera destination point" E_INRANGE
# define E_CAMPOS   ERR "Camera position" E_INRANGE
# define E_LIGHTPOS ERR "Light position" E_INRANGE
# define E_LINT     ERR "Light intensity" E_INRANGE
# define E_SPPOS    ERR "Sphere position" E_INRANGE
# define E_SPRAD    ERR "Sphere radius" E_INRANGE
# define E_SPSPEC   ERR "Sphere specular intensity" E_INRANGE

# define E_AT " Error occured at line: "
# define ERR_AT_NL(nl) MSG(E_AT);ft_putnbr(nl);
# define ERRAT(msg, nl) {ERR_AT_NL(nl);MSG(" \"");MSG(msg);MSGN("\"");}

#endif
