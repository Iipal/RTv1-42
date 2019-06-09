/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_flags.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:28:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/09 22:40:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_FLAGS_H
# define RTV1_FLAGS_H

# include "rtv1_structs.h"

/*
** Flags (and shortcut for that) constant string literals definition:
*/
# define MAX_FLAGS  10

# define F_HELP     "--help"
# define SF_HELP    "-h"

# define MAX_WPARAMS_FLAGS 4
# define F_VPS      "--viewportScale"
# define F_AL       "--ambientLight"
# define F_FTC      "--fpsTextColor"
# define F_FRT      "--fpsRefreshTimer"

# define SF_VPS     "-vps"
# define SF_AL      "-al"
# define SF_FTC     "-ftc"
# define SF_FRT     "-frt"

# define MAX_BOOLEAN_FLAGS 5
# define F_DBG      "--debug"
# define F_NCL      "--noCalcLight"
# define F_TEX      "--textured"
# define F_RLI      "--randomLightsIntense"
# define F_PU       "--printUsage"

# define SF_DBG     "-dbg"
# define SF_NCL     "-ncl"
# define SF_TEX     "-t"
# define SF_RLI     "-rli"
# define SF_PU      "-pu"

# define MAX_OTHER_FLAGS 1
# define F_NB       "--noBorder"

# define SF_NB      "-nb"

/*
** Default flag values:
*/
# define DEF_VIEWPORT_SCALE     1.0f
# define DEF_AMBIENT_LIGHT      100.0f
# define DEF_FPS_TEXT_COLOR     (Color){0x7FFF00}
# define DEF_FPS_REFRESH_TIMER  .25f
# define DEF_DEBUG_MODE         false
# define DEF_NO_CALC_LIGHT      false
# define DEF_PRINT_USAGE        false
# define DEF_TEXTURED           false
# define DEF_RANDOM_INTENSE     false

# define E_MAX_VPS  10
# define E_MAX_AL   25
# define E_MAX_FRT  500

/*
** Flags parsing errno messages:
*/
# define E_INVALID_FLAG     " Invalid flag occured: "
# define E_SEMATICS_FLAG    ERR "Invalid flag semantics occured: "

# define E_VPS      F_VPS " flag"
# define E_AL       F_AL " flag"
# define E_FTC      F_FTC " flag"
# define E_FRT      F_FRT " flag"
# define E_DBG      F_DBG " flag"
# define E_NCL      F_NCL " flag"
# define E_TEX      F_TEX " flag"
# define E_RLI      F_RLI " flag"
# define E_PU       F_PU " flag"

# define E_REPEAT_FLAG(flag) WARNING flag " was already set before. Ignoring."

# define E_MISPARM  "Missed param for "
# define E_MP_VPS   ERR E_MISPARM F_VPS "."
# define E_MP_AL    ERR E_MISPARM F_AL "."
# define E_MP_FTC   ERR E_MISPARM E_FTC "."
# define E_MP_FRT   ERR E_MISPARM E_FRT "."

# define E_UNSIGN   ERR "Only unsigned param values."
# define E_DIGITS   ERR "Only digits in param values string."

# define E_VPS_ZERO  ERR E_VPS " param is 0. Min is 1."
# define E_AL_ZERO   ERR E_AL " param is 0. Min is 1."
# define E_FTC_ZERO  ERR E_FTC " param invalid or 0x0."

# define E_MAX_10   " param greate than 10. Max is 10."
# define E_MAX_25   " param greate than 25. Max is 25."
# define E_MAX_500  " param greate than 500. Max is 500."

# define E_WARN_VPS ERR E_VPS E_MAX_10
# define E_WARN_AL  ERR E_AL E_MAX_25
# define E_WARN_FRT ERR E_FRT E_MAX_500

# define E_FTC0X    "0x"
# define E_FTC_NO0X ERR "Missed \'0x\' for HEX color param in " E_FTC "."
# define E_FTC_HEX  ERR "Invalid HEX color for " E_FTC "."

# define E_USELESS_DONT " useless because you don't use "
# define E_USELESS_USE  " useless because you use "
# define E_USLSS_DONT(f, dont) WARNING f E_USELESS_DONT dont "."
# define E_USLSS_USE(f, use)   WARNING f E_USELESS_USE use "."

/*
**	Flags parsing funcs:
*/
bool			rt_flags_parser(Environment *restrict const env,
									strtab av, const size_t ac);

extern size_t	rt_is_flag_wparam(string flag);

typedef bool	(*t_fwparam)(Flags*, char**, const size_t, size_t *const);
extern bool		f_vps(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		f_al(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		f_ftc(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		f_frt(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);

extern size_t	rt_is_flag_boolean(string flag);

typedef bool	(*t_fbool)(Flags *restrict const);
extern bool		f_dbg(Flags *restrict const boolean_flag);
extern bool		f_ncl(Flags *restrict const boolean_flag);
extern bool		f_tex(Flags *restrict const boolean_flag);
extern bool		f_rli(Flags *restrict const boolean_flag);
extern bool		f_pu(Flags *restrict const boolean_flag);

extern size_t	rt_is_flag_other(string flag);

typedef bool	(*t_fother)(Environment *restrict const env, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		f_nb(Environment *restrict const env, strtab av,
					const size_t ac, size_t *const av_i);

#endif
