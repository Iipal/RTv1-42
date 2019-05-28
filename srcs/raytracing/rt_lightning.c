/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lightning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:04:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/28 19:08:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	add_specular_reflect(const Light *restrict l,
									t_clhelp *restrict const h,
									const double_t obj_spec,
									const Vector v)
{
	const double_t	d = pow(u_vlen(h->p - l->pos), 2);
	const Vector	h_l = u_vnorm(v + h->l);
	const double_t	h_intens = l->intens * fmax(0, h->dnl) + obj_spec
		* (l->intens * pow(fmax(0.0, u_vdot(h->n, h_l)), obj_spec));

	h->i += h_intens / d;
}

static inline void	add_calc_light_intens(const Light *restrict l,
									const Object *restrict const obj,
									t_clhelp *restrict const h,
									const Vector d)
{
	h->dnl = u_vdot(h->n, h->l);
	if (.0f < h->dnl)
		h->i += l->intens * h->dnl / (u_vlen(h->n) * u_vlen(h->l));
	if (.0f < obj->spec)
		add_specular_reflect(l, h, obj->spec, -d);
}

Color				rt_calc_light(Environment *restrict const env,
									t_clhelp *restrict const h,
									const Object *restrict const obj,
									const Vector d)
{
	Object *restrict	shadow;
	Light *restrict		curr_l;
	const Color			bg = sdl_clr_div(obj->clr, env->flags.shadow_bright);
	size_t				i;

	i = ~0L;
	h->i = 0.0f;
	while (++i < env->scene.ins_lights)
	{
		curr_l = &env->scene.lights[i];
		if (.0 >= curr_l->intens)
			continue ;
		h->l = curr_l->pos - h->p;
		env->tmax = 1.0f;
		if (env->scene.is_render_shadow)
		{
			shadow = rt_closest_inter(h->p, h->l, env);
			if (shadow)
				continue ;
		}
		add_calc_light_intens(curr_l, obj, h, d);
	}
	return (.0f < h->i ? sdl_clrs_bright_inc(bg, obj->clr, h->i) : bg);
}
