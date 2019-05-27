/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_vectors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:16:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 20:21:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_VECTORS_H
# define LIBFT_VECTORS_H

# include <math.h>
# include <stdint.h>
# include "libft_macroses.h"

# define DOT  typedef int32_t  Dot __attribute__((vector_size(16),aligned))
# define FDOT typedef double_t fDot __attribute__((vector_size(16),aligned))
# define VEC  typedef double_t Vector __attribute__((vector_size(32),aligned))

# define X(v) v[0]
# define Y(v) v[1]
# define Z(v) v[2]
# define W(v) v[3]

DOT;
FDOT;
VEC;

# define VDISC(k) (Y(k) * Y(k) - 4.0 * X(k) * Z(k))

/*
**	u_ prefix is short name for utils.
*/
extern double_t	u_vlen(const Vector v);
extern double_t	u_vdot(const Vector v1, const Vector v2);

extern Vector	u_vnorm(const Vector v);

extern Vector	u_vmuld(const Vector v, const double_t d);
extern Vector	u_vaddd(const Vector v, const double_t d);
extern Vector	u_vsubd(const Vector v, const double_t d);
extern Vector	u_vdivd(const Vector v, const double_t d);

extern Vector	u_vmulv(const Vector a, const Vector b);
extern Vector	u_vaddv(const Vector a, const Vector b);
extern Vector	u_vsubv(const Vector a, const Vector b);
extern Vector	u_vdivv(const Vector a, const Vector b);

extern Vector	u_vinvert(const Vector v);

extern bool		u_vec_range(Vector v,
					const double_t max_range,
					const double_t min_range);
extern bool		u_isd_range(double_t a,
					const double_t max_range,
					const double_t min_range);
extern double_t	u_d_range(double_t x,
					const double_t max_range,
					const double_t min_range);

#endif
