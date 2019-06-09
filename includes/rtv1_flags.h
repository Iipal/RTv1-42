/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_flags.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 00:28:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/09 11:46:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_FLAGS_H
# define RTV1_FLAGS_H

/*
** Flags (and shortcut for that) constant string literals definition:
*/
# define MAX_FLAGS  10
# define F_HELP     "--help"
# define F_DBG      "--debug"
# define F_VPS      "--viewportScale"
# define F_AL       "--ambientLight"
# define F_FTC      "--fpsTextColor"
# define F_FRT      "--fpsRefreshTimer"
# define F_NCL      "--noCalcLight"
# define F_TEX      "--textured"
# define F_RLI      "--randomLightsIntense"
# define F_PU       "--printUsage"

# define SF_HELP    "-h"
# define SF_VPS     "-vps"
# define SF_AL      "-al"
# define SF_FTC     "-ftc"
# define SF_FRT     "-frt"
# define SF_DBG     "-dbg"
# define SF_NCL     "-ncl"
# define SF_TEX     "-t"
# define SF_RLI     "-rli"
# define SF_PU      "-pu"

/*
** Default flag values:
*/
# define DEF_VIEWPORT_SCALE     1.0f
# define DEF_AMBIENT_LIGHT      100.0f
# define DEF_FPS_TEXT_COLOR     (Color){0x7FFF00}
# define DEF_FPS_REFRESH_TIMER  .25f
# define DEF_DEBUG_MODE         false
# define DEF_NOT_CALC_LIGHT     false
# define DEF_PRINT_USAGE        false
# define DEF_TEXTURED           false
# define DEF_RANDOM_INTENSE     false

/*
** Flags parsing errno messages:
*/
# define E_INVALID_FLAG     " Invalid flag occured: "
# define E_CEMANTIC_FLAG    ERR "Invalid flag cemantic occured: "

# define E_DBG      F_DBG " flag"
# define E_VPS      F_VPS " flag"
# define E_AL       F_AL " flag"
# define E_FTC      F_FTC " flag"
# define E_FRT      F_FRT " flag"
# define E_NCL      F_NCL " flag"
# define E_RLI      F_RLI " flag"
# define E_PU       F_PU " flag"

# define E_MAX_VPS  10
# define E_MAX_AL   25
# define E_MAX_FRT  500

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

# define E_USELESS_FRT WARNING E_FRT " useless because you don't use " E_DBG "."
# define E_USELESS_FTC WARNING E_FTC " useless because you don't use " E_DBG "."
# define E_USELESS_RLI WARNING E_RLI " useles because you use " E_NCL "."
# define E_USELESS_AL  WARNING E_AL " useles because you use " E_NCL "."
# define E_USELESS_PU  WARNING E_PU " useless because you don't use " E_DBG "."

/*
** Flags struct:
*/
struct			s_flags
{
	float_t	viewport_scale;
	double	ambient_light;
	Color	fps_text_color;
	bool	is_parsed_ftc;
	float_t	fps_refresh_timer;
	bool	is_parsed_frt;
	bool	debug_mode;
	bool	print_usage;
	bool	no_calc_light;
	bool	textured;
	bool	random_lights_intense;
};

# define FLAGS typedef struct s_flags   Flags

FLAGS;

/*
**	Flags parsing funcs:
*/
bool			rt_flags_parser(Flags *const f, strtab av, const size_t ac);

typedef bool	(*t_fn_fparse)(Flags *, char**, const size_t, size_t *const);
extern bool		rt_fhelp(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fvps(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fal(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fftc(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_ffrt(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fdbg(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fncl(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_ftex(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_frli(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);
extern bool		rt_fpu(Flags *const f, strtab av,
					const size_t ac, size_t *const av_i);

void			rt_randomatic_lights_intense(Light *restrict const lights,
											const size_t ins_lights);

#endif
