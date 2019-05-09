/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lightning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:04:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/09 17:50:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

inline static void	add_specular_reflect(Environment *env, t_clhelp *h,
						Object *obj, t_vec d)
{
	h->h = d + h->x;
	h->h = (t_vec){h->h[X] / VLEN(h->h),
		h->h[Y] / VLEN(h->h), h->h[Z] / VLEN(h->h)};
	h->h_intense = env->s.l.intens * fmax(0, h->dnl) + obj->spec
	* env->s.l.intens * pow(fmax(0, VDOT(h->n, h->h)), obj->spec);
	h->d = h->p - env->s.l.pos;
	h->i += h->h_intense / VLEN(h->d);
}

inline Color		rt_calculate_light(Environment *env, Object *obj, t_vec d)
{
	t_clhelp	h;

	C(t_clhelp, &h, 1);
	h.tmp1 = obj->clr;
	h.tmp2 = h.tmp1;
	h.cd = (t_vec){env->s.cobj * d[X], env->s.cobj * d[Y], env->s.cobj * d[Z]};
	h.p = env->s.cam.pos + h.cd;
	h.n = h.p - obj->pos;
	h.n = (t_vec){h.n[X] / VLEN(h.n), h.n[Y] / VLEN(h.n), h.n[Z] / VLEN(h.n)};
	h.x = env->s.l.pos - h.p;
	h.dnl = VDOT(h.n, h.x);
	h.i = 0.0f;
	if (.0f < h.dnl)
		h.i += env->s.l.intens * h.dnl / (VLEN(h.n) * VLEN(h.x));
	if (.0f < obj->spec)
		add_specular_reflect(env, &h, obj, -d);
	return ((.0f >= h.i) ? obj->clr
		: (*sdl_clrs_add(&h.tmp2, *sdl_clr_mul(&h.tmp1, h.i))));
}
