/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_vectors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:16:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/18 21:42:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_VECTORS_H
# define LIBFT_VECTORS_H

# include <math.h>
# include <stdint.h>

# define DOT typedef int32_t  Dot __attribute__((vector_size(16),aligned))
# define VEC typedef double_t Vector __attribute__((vector_size(32),aligned))

# define X(v) v[0]
# define Y(v) v[1]
# define Z(v) v[2]
# define W(v) v[3]

DOT;
VEC;

# define VLEN(v) sqrt(X(v) * X(v) + Y(v) * Y(v) + Z(v) * Z(v))
# define VDOT(v1, v2) (X(v1) * X(v2) + Y(v1) * Y(v2) + Z(v1) * Z(v2))
# define VNORM(v) X(v)/sqrt(VDOT(v,v)),Y(v)/sqrt(VDOT(v,v)),Z(v)/sqrt(VDOT(v,v))
# define VMUL(v, d) (Vector){X(v) * d, Y(v) * d, Z(v) * d}
# define VMULR(v, d) (Vector){d * X(v), d * Y(v), d * Z(v)}
# define VDISC(k) (Y(k) * Y(k) - 4.0 * X(k) * Z(k))

/*
**	u_ prefix is short name for utils.
*/
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
