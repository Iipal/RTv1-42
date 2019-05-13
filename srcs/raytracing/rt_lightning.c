/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lightning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:04:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/13 12:46:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	add_specular_reflect(Light l, t_clhelp *h,
										Object *obj, t_v v)
{
	h->h = v + h->l;
	h->h = (t_v){X(h->h) / VLEN(h->h),
		Y(h->h) / VLEN(h->h), Z(h->h) / VLEN(h->h)};
	h->h_intense = l.intens * fmax(0, h->dnl) + obj->spec
		* l.intens * pow(fmax(0, VDOT(h->n, h->h)), obj->spec);
	h->d = h->p - l.pos;
	h->i += h->h_intense / VLEN(h->d);
}

Color				rt_calculate_light(Environment *env, Object *obj, t_v d)
{
	Object		*shadow;
	t_clhelp	h;
	size_t		i;

	i = ~0L;
	C(t_clhelp, &h, 1);
	h.c = (t_v){env->s.cobj * X(d), env->s.cobj * Y(d), env->s.cobj * Z(d)};
	h.p = env->s.cam.pos + h.c;
	h.n = h.p - obj->pos;
	h.n = (t_v){X(h.n) / VLEN(h.n), Y(h.n) / VLEN(h.n), Z(h.n) / VLEN(h.n)};
	while (++i < env->s.ins_l)
	{
		h.l = env->s.l[i].pos - h.p;
		if ((shadow = rt_closest_inter(h.p, h.l, env, true)))
			continue ;
		h.dnl = VDOT(h.n, h.l);
		if (.0f < h.dnl)
			h.i += env->s.l[i].intens * h.dnl / (VLEN(h.n) * VLEN(h.l));
		if (.0f < obj->spec)
			add_specular_reflect(env->s.l[i], &h, obj, -d);
	}
	return (.0f < h.i ?
		sdl_clrs_bright_inc(CLR_BLACK, obj->clr, h.i) : CLR_BLACK);
}
