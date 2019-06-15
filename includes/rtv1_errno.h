/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_errno.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 09:33:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/15 09:37:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_ERRNO_H
# define RTV1_ERRNO_H

# define RTV1_MAIN_USAGE    "Usage: ./RTv1 [flags-params] <scene_name>.json"

# define PERR       " ERROR"
# define ERR        " ERROR: "
# define WARNING    " WARNING: "

# define E_DIR      ERR "Invalid executable path."
# define E_ALLOC    ERR "Where is memory, pal ?"

# define E_FNMAE    ERR "Missing file name."
# define E_EFILE    ERR "Empty scene file."
# define E_FILEXT   ERR "Invalid scene file extension. (.json)"
# define E_ISYNTAX  ERR "Invalid scene file syntax."

#endif
