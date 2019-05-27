/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_vectors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:16:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/27 16:06:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_VECTORS_H
# define LIBFT_VECTORS_H

# include <math.h>
# include <stdint.h>
# include "libft_macroses.h"

typedef struct s_dot
{
	int32_t	x;
	int32_t	y;
} __attribute__((aligned(8)))	Dot;

typedef struct s_fdot
{
	double_t	x;
	double_t	y;
} __attribute__((aligned(16)))	fDot;

typedef struct s_vector
{
	double_t	x;
	double_t	y;
	double_t	z;
	double_t	w;
} __attribute__((aligned(32)))	Vector;

// # define DOT typedef int32_t  Dot __attribute__((vector_size(16),aligned))
// # define VEC typedef double_t Vector __attribute__((vector_size(32),aligned))

# define X(v) v.x
# define Y(v) v.y
# define Z(v) v.z
# define W(v) v.w

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
