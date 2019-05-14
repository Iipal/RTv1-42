/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lightning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:04:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/14 17:17:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	add_specular_reflect(Light l, t_clhelp *h,
									const float_t obj_spec, t_v v)
{
	h->h = v + h->l;
	h->h = (t_v){X(h->h) / VLEN(h->h),
		Y(h->h) / VLEN(h->h), Z(h->h) / VLEN(h->h)};
	h->h_intense = l.intens * fmax(0, h->dnl) + obj_spec
		* l.intens * pow(fmax(0, VDOT(h->n, h->h)), obj_spec);
	h->d = h->p - l.pos;
	h->i += h->h_intense / VLEN(h->d);
}

Color				rt_calculate_light(Environment *env, t_clhelp *h,
								const Object *obj, const t_v d)
{
	Object		*shadow;
	size_t		i;
	const Color	bg_clr = sdl_clr_div(obj->clr, env->flags.shadows_bright);

	i = ~0L;
	while (++i < env->s.ins_l)
	{
		if (.0f >= env->s.l[i].intens)
			continue ;
		h->l = env->s.l[i].pos - h->p;
		if ((shadow = rt_closest_inter(h->p, h->l, env, true)))
			continue ;
		h->dnl = VDOT(h->n, h->l);
		if (.0f < h->dnl)
			h->i += env->s.l[i].intens * h->dnl / (VLEN(h->n) * VLEN(h->l));
		if (.0f < obj->spec)
			add_specular_reflect(env->s.l[i], h, obj->spec, -d);
	}
	return (.0f < h->i ? sdl_clrs_bright_inc(bg_clr, obj->clr, h->i) : bg_clr);
}
