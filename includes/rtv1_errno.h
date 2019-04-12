/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_errno.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:05:25 by tmaluh            #+#    #+#             */
/*   Updated: 2019/04/12 12:56:20 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_ERRNO_H
# define RTV1_ERRNO_H

# define E_USAGE    "Usage: ./RTv1 <scene_name>.rtv1"

# define ERR        " ERROR: "

# define E_DIR      ERR "Invalid executable path."
# define E_ALLOC    ERR "Where is memory, pal ?"

# define E_FILE     " ERROR"
# define E_FNLESS   ERR "Too short file name."
# define E_FILEXT   ERR "Invalid scene file extention. (.rtv1)"
# define E_FEMPTY   ERR "File is empty."
# define E_WINSIZE  ERR "Invalid window sizes. Less than 400px or too big."
# define E_ISYNTAX  ERR "Invalid scene file syntax."

#endif
