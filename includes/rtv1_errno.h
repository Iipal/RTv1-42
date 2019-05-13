/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_errno.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:05:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/13 21:15:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_ERRNO_H
# define RTV1_ERRNO_H

# define E_USAGE    "Usage: ./RTv1 [flags-params] <scene_name>.rtv1"

# define PERR       " ERROR"
# define ERR        " ERROR: "
# define WARNING    " WARNING: "

# define E_FNMAE    ERR "Missing file name."
# define E_EFILE    ERR "Empty scene file."
# define E_FILEXT   ERR "Invalid scene file extension. (.rtv1)"
# define E_ISYNTAX  ERR "Invalid scene file syntax."

# define E_DIR      ERR "Invalid executable path."
# define E_ALLOC    ERR "Where is memory, pal ?"

# define E_OBJ      ERR "Unknown object type."

# define E_DUP      ERR "In scene cannot be more than "
# define E_DCAMERA  E_DUP "1 camera."

# define E_MLIGHTS  ERR "Maximum lights in scene: 5."

# define E_NOCAM    ERR "No camera in scene founded."
# define E_NOLIGHT  ERR "No origin light in scene founded."
# define E_NOOBJS   ERR "No objects in scene founded."

# define E_INRANGE  " not in available range."

# define E_CAMDIR   ERR "Camera destination point" E_INRANGE
# define E_CAMPOS   ERR "Camera position" E_INRANGE
# define E_LIGHTPOS ERR "Light position" E_INRANGE
# define E_LINTENSE ERR "Light intensity" E_INRANGE
# define E_SPPOS    ERR "Sphere position" E_INRANGE
# define E_SPRAD    ERR "Sphere radius" E_INRANGE
# define E_SPSPEC   ERR "Sphere specular intensity" E_INRANGE

# define E_AT " Error occured at line: "
# define ERR_AT_NL(nl) MSG(E_AT);ft_putnbr(nl)
# define ERRAT(msg, nl) {ERR_AT_NL(nl);MSG(" \"");MSG(msg);MSGN("\"");}

# define E_IFLAG    ERR "Invalid flag."

# define E_MISPARM  "Missed param for flag "

# define E_MP_VPS   ERR E_MISPARM F_VPS "."
# define E_MP_SB    ERR E_MISPARM F_SB "."

# define E_UNSIGN   ERR "Only unsigned param values."
# define E_DIGITS   ERR "Only digits in param values string."

# define E_WVPSZERO WARNING "Viewport scale flag param is 0. Min is 1."

# define E_WF "flag param was greate than"

# define E_WARNVPS  WARNING "Viewport scale " E_WF " 10. Max is 10."
# define E_WARNSB   WARNING "Shadow bright " E_WF " 100. Max is 100."

#endif
