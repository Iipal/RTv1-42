/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lightning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:04:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/22 10:27:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	add_specular_reflect(Light *restrict const l,
									t_clhelp *restrict const h,
									const float_t obj_spec,
									const Vector v)
{
	const Vector	d = h->p - l->pos;
	Vector			h_l;
	double_t		vlen_h;
	double_t		h_intens;

	h_l = v + h->l;
	vlen_h = u_vlen(h_l);
	h_l = (Vector){X(h_l) / vlen_h, Y(h_l) / vlen_h, Z(h_l) / vlen_h};
	h_intens = (l->intens * fmax(0, h->dnl) + obj_spec)
		* (l->intens * pow(fmax(0.0f, u_vdot(h->n, h_l)), obj_spec));
	h->i += h_intens / pow(u_vlen(d), 2.6);
}

Color				rt_calc_light(Environment *const env,
								t_clhelp *restrict const h,
								const Object *const obj,
								const Vector d)
{
	Object		*shadow;
	size_t		i;
	const Color	bg_clr = sdl_clr_div(obj->clr, env->flags.shadows_bright);

	i = ~0L;
	h->i = 0.0f;
	while (++i < env->s.ins_l)
	{
		if (.0f >= env->s.l[i].intens)
			continue ;
		h->l = env->s.l[i].pos - h->p;
		env->t_max = 1.0f;
		if (env->s.is_render_shadow
		&& (shadow = rt_closest_inter(h->p, h->l, env)))
			continue ;
		h->dnl = u_vdot(h->n, h->l);
		if (.0f < h->dnl)
			h->i += env->s.l[i].intens * h->dnl / (u_vlen(h->n) * u_vlen(h->l));
		if (.0f < obj->spec)
			add_specular_reflect(&env->s.l[i], h, obj->spec, -d);
	}
	return (.0f < h->i ? sdl_clrs_bright_inc(bg_clr, obj->clr, h->i) : bg_clr);
}
