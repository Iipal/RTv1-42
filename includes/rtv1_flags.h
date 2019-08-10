/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_flags.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:28:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/10 14:58:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_FLAGS_H
# define RTV1_FLAGS_H

# include "rtv1_structs.h"

extern uint16_t	g_flags;

/*
** Flags (and shortcut for that) constant string literals definition:
*/
# define MAX_FLAGS 10

# define F_HELP  "--help"
# define SF_HELP "-h"

# define MAX_WPARAMS_FLAGS 5
# define F_VPS  "--viewportScale"
# define F_AL   "--ambientLight"
# define F_FTC  "--fpsTextColor"
# define F_FRT  "--fpsRefreshTimer"
# define F_AA   "--antiAliasing"

# define SF_VPS "-vps"
# define SF_AL  "-al"
# define SF_FTC "-ftc"
# define SF_FRT "-frt"
# define SF_AA  "-aa"

# define F_BIT_VPS (1 << 0)
# define F_BIT_AL  (1 << 1)
# define F_BIT_FTC (1 << 2)
# define F_BIT_FRT (1 << 3)
# define F_BIT_AA  (1 << 4)

# define MAX_BOOLEAN_FLAGS 5
# define F_DBG  "--debug"
# define F_NCL  "--noCalcLight"
# define F_TEX  "--textured"
# define F_RLI  "--randomLightsIntense"
# define F_PU   "--printUsage"

# define SF_DBG "-dbg"
# define SF_NCL "-ncl"
# define SF_TEX "-t"
# define SF_RLI "-rli"
# define SF_PU  "-pu"

# define F_BIT_DBG (1 << 5)
# define F_BIT_NCL (1 << 6)
# define F_BIT_TEX (1 << 7)
# define F_BIT_RLI (1 << 8)
# define F_BIT_PU  (1 << 9)

# define MAX_OTHER_FLAGS 1
# define F_NB  "--noBorder"

# define SF_NB "-nb"

# define F_BIT_NB (1 << 10)

# define F_BIT_SHADOWS (1 << 11)

/*
** Default flag values:
*/
# define DEF_FPS_TEXT_COLOR    (Color){0x7FFF00}
# define DEF_FPS_REFRESH_TIMER .25f
# define DEF_VIEWPORT_SCALE    1.0f
# define DEF_AMBIENT_LIGHT     100.0f
# define DEF_ANTI_ALIASING     0

# define E_MAX_VPS 10
# define E_MAX_AL  100
# define E_MAX_FRT 500
# define E_MAX_AA  8

/*
** Flags parsing errno messages:
*/
# define E_INVALID_FLAG  " Invalid flag occured: "
# define E_SEMATICS_FLAG ERR "Invalid flag semantics occured: "

# define E_VPS F_VPS " flag"
# define E_AL  F_AL " flag"
# define E_FTC F_FTC " flag"
# define E_FRT F_FRT " flag"
# define E_AA  F_AA " flag"
# define E_DBG F_DBG " flag"
# define E_NCL F_NCL " flag"
# define E_TEX F_TEX " flag"
# define E_RLI F_RLI " flag"
# define E_PU  F_PU " flag"

# define E_UNSIGN ERR "Only unsigned param value."
# define E_DIGITS ERR "Invalid value in params."

# define E_REPEAT_FLAG(flag) WARNING flag " was already set before. Ignoring."
# define E_MISS_PARAM(flag)  ERR "Missed param for " flag "."
# define E_ZERO_PARAM(flag)  ERR flag " param is 0."

# define E_FTC_ZERO ERR E_FTC " param invalid or 0x0."

# define E_AA_USLS  ERR E_AA " param is 0 or 1. It's make no sense."

# define E_MAX_8  " param greate than 8. Max is 8."
# define E_MAX_10  " param greate than 10. Max is 10."
# define E_MAX_100 " param greate than 100. Max is 100."
# define E_MAX_500 " param greate than 500. Max is 500."

# define E_WARN_AA  ERR E_AA E_MAX_8
# define E_WARN_AL  ERR E_AL E_MAX_100
# define E_WARN_VPS ERR E_VPS E_MAX_10
# define E_WARN_FRT ERR E_FRT E_MAX_500

# define E_FTC0X    "0x"
# define E_FTC_NO0X ERR "Missed \'0x\' for HEX color param in " E_FTC "."
# define E_FTC_HEX  ERR "Invalid HEX color for " E_FTC "."

# define E_USELESS_DONT_MSG " useless because you don't use "
# define E_USELESS_USE_MSG  " useless because you use "
# define E_USELESS_DONT(f, dont) WARNING f E_USELESS_DONT_MSG dont "."
# define E_USELESS_USE(f, use)   WARNING f E_USELESS_USE_MSG use "."

/*
**	Flags parsing funcs:
*/
bool	rt_parse_flags(Environment *const env, char **av, size_t const ac);

size_t	rt_is_flag_wparam(char const *flag);

typedef bool	(*t_fwparam)(Flags*, char**, size_t const, size_t *const);
bool	f_vps(Flags *const f, char **av,
			size_t const ac, size_t *const av_i);
bool	f_al(Flags *const f, char **av,
			size_t const ac, size_t *const av_i);
bool	f_ftc(Flags *const f, char **av,
			size_t const ac, size_t *const av_i);
bool	f_frt(Flags *const f, char **av,
			size_t const ac, size_t *const av_i);
bool	f_aa(Flags *const f, char **av,
			size_t const ac, size_t *const av_i);

size_t	rt_is_flag_boolean(char const *flag);

typedef bool	(*t_fbool)(void);
bool	f_dbg(void);
bool	f_ncl(void);
bool	f_tex(void);
bool	f_rli(void);
bool	f_pu(void);

size_t	rt_is_flag_other(char const *flag);

typedef bool	(*t_fother)(Environment *restrict const env, char **av,
					size_t const ac, size_t *const av_i);
bool	f_nb(Environment *restrict const env, char **av,
			size_t const ac, size_t *const av_i);

bool	rt_parsed_flags_validation(Flags const *const f);

#endif
