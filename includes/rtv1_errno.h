/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_errno.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:05:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 22:58:28 by tmaluh           ###   ########.fr       */
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
# define E_NOLIGHT  ERR "No origin lights in scene founded."
# define E_NOOBJS   ERR "No objects in scene founded."

# define E_INRANGE  " not in available range"
# define E_CAMDIR   "Camera destination point(rotation)" E_INRANGE
# define E_CAMPOS   "Camera position" E_INRANGE
# define E_LIGHTPOS "Light position" E_INRANGE
# define E_LINTENSE "Light intensity" E_INRANGE
# define E_OBJPOS   "Object position" E_INRANGE
# define E_OBJRAD   "Object radius" E_INRANGE
# define E_OBJSPEC  "Object specular intensity" E_INRANGE
# define E_OCONERAD "Cone radius" E_INRANGE ". min 1 - max 3."

# define ERR_IN_NUM(msg, n) MSG(msg);ft_putnbr(n)
# define ERRIN(msg, n, err) {ERR_IN_NUM(err,n);MSG(" \"");MSG(msg);MSGN("\"");}

# define E_OCCURED  " Error occured "
# define E_IN_LINE  E_OCCURED "at line: "
# define E_IN_LIGHT E_OCCURED "in light origin: "
# define E_IN_OBJ   E_OCCURED "in object: "

# define E_IFLAG    ERR "Invalid flag."
# define E_DBG      "--debug flag"
# define E_VPS      "--viewport-scale flag"
# define E_SB       "--shadow-bright flag"
# define E_FTC      "--fps-text-color flag"
# define E_FRT      "--fps-refresh-time flag"
# define E_NCL      "--no-calc-light flag"

# define E_MAX_VPS  10
# define E_MAX_SB   25
# define E_MAX_FRT  500

# define E_MISPARM  "Missed param for "
# define E_MP_VPS   ERR E_MISPARM F_VPS "."
# define E_MP_SB    ERR E_MISPARM F_SB "."
# define E_MP_FTC   ERR E_MISPARM E_FTC "."
# define E_MP_FRT   ERR E_MISPARM E_FRT "."

# define E_UNSIGN   ERR "Only unsigned param values."
# define E_DIGITS   ERR "Only digits in param values string."

# define E_VPS_ZERO  ERR E_VPS " param is 0. Min is 1."
# define E_SB_ZERO   ERR E_SB " param is 0. Min is 1."
# define E_FTC_ZERO  ERR E_FTC " param invalid or 0x0."

# define E_MAX_10   " param greate than 10. Max is 10."
# define E_MAX_25   " param greate than 25. Max is 25."
# define E_MAX_500  " param greate than 500. Max is 500."

# define E_WARN_VPS ERR E_VPS E_MAX_10
# define E_WARN_SB  ERR E_SB E_MAX_25
# define E_WARN_FRT ERR E_FRT E_MAX_500

# define E_FTC0X    "0x"
# define E_FTC_NO0X ERR "Missed \'0x\' for HEX color param in " E_FTC "."
# define E_FTC_HEX  ERR "Invalid HEX color for " E_FTC "."

# define E_USELESS_FTC WARNING E_FTC " useless because you don't use " E_DBG "."
# define E_USELESS_FRT WARNING E_FRT " useless because you don't use " E_DBG "."
# define E_USELESS_SB  WARNING E_SB " useles because you use " E_NCL "."

#endif
