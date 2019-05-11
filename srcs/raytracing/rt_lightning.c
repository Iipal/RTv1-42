/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lightning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:04:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/11 12:36:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

 inline t_vec add_mult(t_vec vec, double_t mult)
{
	X(vec) *= mult;
	Y(vec) *= mult;
	Z(vec) *= mult;
	return (vec);
}

static inline void	add_specular_reflect(Environment *env,
						t_clhelp *h, Object *obj, t_vec d)
{
	/* t_vec R = add_mult(h->n, 2.0f * VDOT(h->n, h->l)) - h->l;
	double_t r_dot_v = VDOT(R, d);
	if (.0f < r_dot_v)
		h->i += env->s.l.intens
			* pow(r_dot_v / (VLEN(R) * VLEN(d)), obj->spec); */
	h->h = d + h->l;
	h->h = (t_vec){X(h->h) / VLEN(h->h),
		Y(h->h) / VLEN(h->h), Z(h->h) / VLEN(h->h)};
	h->h_intense = env->s.l.intens * fmax(0, h->dnl) + obj->spec
	* env->s.l.intens * pow(fmax(0, VDOT(h->n, h->h)), obj->spec);
	h->d = h->p - env->s.l.pos;
	h->i += h->h_intense / VLEN(h->d);
}

inline Color		rt_calculate_light(Environment *env, Object *obj, t_vec d)
{
	t_clhelp	h;

	h.i = 0.0f;
	C(t_clhelp, &h, 1);
	h.tmp1 = obj->clr;
	h.tmp2 = h.tmp1;
	h.cd = (t_vec){env->s.cobj * X(d), env->s.cobj * Y(d), env->s.cobj * Z(d)};
	h.p = env->s.cam.pos + h.cd;
	h.n = h.p - obj->pos;
	h.n = (t_vec){X(h.n) / VLEN(h.n), Y(h.n) / VLEN(h.n), Z(h.n) / VLEN(h.n)};
	h.l = env->s.l.pos - h.p;
	obj = rt_closest_inter(h.p, h.l, env);
	if (NULL == obj)
		return (h.tmp1);
	h.dnl = VDOT(h.n, h.l);
	if (.0f < h.dnl)
		h.i += env->s.l.intens * h.dnl / (VLEN(h.n) * VLEN(h.l));
	if (.0f < obj->spec)
		add_specular_reflect(env, &h, obj, -d);
	return (.0f >= h.i ? obj->clr : COLOR_MULT(h.tmp2, h.tmp1, h.i));
}
