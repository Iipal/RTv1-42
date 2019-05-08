/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lightning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:04:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/09 00:38:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	Calculate point light type
*/

static inline Color	add_compute_light(t_clhelp h)
{
	double_t	i;
	Color		tmp, tmp2;
	const Vec	x = {h.l.pos.x - h.p.x, h.l.pos.y - h.p.y, h.l.pos.z - h.p.z};
	const float	dot_nl = VDOT(h.n, x);

	tmp2 = tmp = h.obj.clr;
	i = 0.0;
	if (.0f < dot_nl)
		i += h.l.intensity * dot_nl / (VLEN(h.n) * VLEN(x));
	if (0 < h.s)
	{
		Vec H = {h.v.x + x.x, h.v.y + x.y, h.v.z + x.z};
		H = (Vec) {H.x / VLEN(H), H.y / VLEN(H), H.z / VLEN(H)};
		float_t intens = h.l.intensity * fmax(0, dot_nl) +
			h.s * h.l.intensity * pow(fmax(0, VDOT(h.n, H)), h.s);
		Vec DDD = {h.p.x - h.l.pos.x, h.p.y - h.l.pos.y, h.p.z - h.l.pos.z};
		i += intens / VLEN(DDD);
	}
	return (0.0f < i ? *sdl_clrs_add(&tmp2, *sdl_clr_mul(&tmp, i)) : h.obj.clr);
}

inline Color		rt_calculate_light(Environment *env, int32_t i, Vec d)
{
	t_lhelp	lh;

	if (env->s.ins_objs <= i)
		i = env->s.ins_objs - 1;
	lh.cd = (Vec){env->s.cobj * d.x,
				env->s.cobj * d.y,
				env->s.cobj * d.z};
	lh.p = (Vec){env->s.cam.pos.x + lh.cd.x,
				env->s.cam.pos.y + lh.cd.y,
				env->s.cam.pos.z + lh.cd.z};
	lh.n = (Vec){lh.p.x - env->s.objs[i].pos.x,
				lh.p.y - env->s.objs[i].pos.y,
				lh.p.z - env->s.objs[i].pos.z};
	lh.n = (Vec){lh.n.x / VLEN(lh.n),
				lh.n.y / VLEN(lh.n),
				lh.n.z / VLEN(lh.n)};
	return (add_compute_light((t_clhelp){env->s.objs[i], lh.p, lh.n,
				env->s.l, env->s.objs[i].spec, (Vec){-d.x, -d.y, -d.z}}));
}
